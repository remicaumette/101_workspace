import Project from '../model/project';
import User from '../model/user';
import Deployment from '../deployment';

export async function owner({ id }) {
    const project = await Project.findOne({ where: { id } });
    const user = await User.findById(project.userId);

    return user.serialize();
}

export async function url({ id }) {
    const port = await Deployment.getPort(id);
    return port ? `http://${process.env.BASE_URL || 'localhost'}:${port}` : null;
}
