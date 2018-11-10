import User from '../model/user';
import Project from '../model/project';

export async function me(_, args, { user }) {
    return user;
}

export async function users() {
    const findUsers = await User.findAll({ order: [['createdAt', 'DESC']] });
    return findUsers
        .map(user => user.serialize());
}

export async function userById(_, { id }) {
    const user = await User.findOne({ where: { id } });
    return user ? user.serialize() : null;
}

export async function userByName(_, { name }) {
    const user = await User.findOne({ where: { username: name } });
    return user ? user.serialize() : null;
}

export async function projects() {
    const findProjects = await Project.findAll({ order: [['createdAt', 'DESC']] });
    return findProjects
        .map(project => project.serialize());
}

export async function projectById(_, { id }) {
    const project = await Project.findOne({ where: { id } });
    return project ? project.serialize() : null;
}

export async function projectByName(_, { name }) {
    const project = await Project.findOne({ where: { name } });
    return project ? project.serialize() : null;
}
