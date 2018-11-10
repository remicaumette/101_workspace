import { promises as fs, createWriteStream } from 'fs';
import { join } from 'path';
import { tmpdir } from 'os';
import { v4 as uuid } from 'uuid';
import { info } from 'signale';
import Docker from 'dockerode';
import decompress from 'decompress';

const docker = new Docker();

function promisifyStream(stream) {
    return new Promise((resolve, reject) => {
        stream.on('data', () => null);
        stream.on('end', resolve);
        stream.on('error', reject);
    });
}

export async function destroy(project) {
    info(`Destroying container for ${project.name}...`);

    try {
        // delete container
        const container = await docker.getContainer(project.id);

        if (container) {
            await container.stop();
            await container.remove();

            // delete image
            const image = await docker.getImage(`${project.id}:latest`);
            await image.remove();
        }
    } catch (e) {
        if (e.message.match(/No such container/gi).length === 0) {
            throw e;
        }
    }
}

export async function getPort(id) {
    try {
        const container = await docker.getContainer(id);
        const containerData = await container.inspect();

        return containerData.NetworkSettings.Ports['80/tcp'][0].HostPort;
    } catch (e) {
        return null;
    }
}

export async function deploy(project, filename, stream) {
    info(`Deploying container for ${project.name}...`);

    const tempDir = await fs.mkdtemp(join(tmpdir(), `${uuid()}-`));
    const archivePath = join(tempDir, filename);
    const fileStream = createWriteStream(archivePath);
    stream.pipe(fileStream);

    await promisifyStream(stream);
    await decompress(archivePath, tempDir);

    // destroy old container
    if (await getPort(project.id)) {
        await destroy(project);
    }

    // build image
    if (project.runtime !== 'docker') {
        await fs.copyFile(join(__dirname, '..', '..', 'runtimes', project.runtime.toLowerCase(), 'Dockerfile'), join(tempDir, 'Dockerfile'));
    }
    const buildStream = await docker.buildImage({ context: tempDir }, { t: `${project.id}:latest` });
    await promisifyStream(buildStream);

    // create container
    const container = await docker.createContainer({
        name: project.id,
        Image: `${project.id}:latest`,
        ExposedPorts: { '80/tcp': {} },
        HostConfig: {
            PortBindings: {
                '80/tcp': [
                    {
                        HostIp: '',
                        HostPort: '',
                    },
                ],
            },
        },
    });

    // start container
    await container.start();
}
