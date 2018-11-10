import Project from '../model/project';

export async function projects({ id }) {
    const userProjects = await Project.findAll({ where: { userId: id } });
    return userProjects
        .map(project => project.serialize());
}

export async function admin({ username }) {
    const admins = process.env.ADMIN;

    return admins ? admins.trim().split(',')
        .map(adminUsername => adminUsername.toLowerCase())
        .includes(username.toLowerCase()) : false;
}
