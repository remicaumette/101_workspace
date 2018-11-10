import { GraphQLError } from 'graphql';
import { extname } from 'path';
import Joi from 'joi';
import Sequelize from 'sequelize';
import { comparePassword, hashPassword } from '../utils/password';
import { createToken as generateToken } from '../utils/token';
import Project from '../model/project';
import User from '../model/user';
import Deployment from '../deployment';

const CREATE_USER_VALIDATION = Joi.object().keys({
    email: Joi.string().email(),
    username: Joi.string().regex(/^[a-zA-Z0-9_-]*/gi).min(3).max(30).required(),
    password: Joi.string().min(6).max(50).required(),
});

const CREATE_PROJECT_VALIDATION = Joi.object().keys({
    name: Joi.string().regex(/^[a-zA-Z0-9_-]*/gi).disallow('new').min(3).max(30).required(),
    runtime: Joi.string().required(),
    description: Joi.string().allow('').max(2000).optional(),
});

export async function createUser(_, { email, username, password }) {
    const validation = Joi.validate({ email, username, password }, CREATE_USER_VALIDATION);

    if (validation.error) {
        throw new GraphQLError(validation.error.details[0].message);
    }

    const exists = await User.findOne({ where: Sequelize.or({ email }, { username }) });

    if (exists) {
        throw new GraphQLError('This email or username is already used.');
    }

    const hashedPassword = await hashPassword(password);
    const user = await User.create({ email, username, password: hashedPassword });

    return user.serialize();
}

export async function updateUser(_, { id, description }) {
    const user = await User.findById(id);
    user.description = description;
    await user.save();

    return user.serialize();
}

export async function deleteUser(_, { id }) {
    return User.destroy({ where: { id } });
}

export async function createToken(_, { email, password }) {
    const user = await User.findOne({ where: { email } });

    if (!user) {
        throw new GraphQLError('Invalid email or password.');
    }

    const match = await comparePassword(password, user.password);

    if (!match) {
        throw new GraphQLError('Invalid email or password.');
    }

    return generateToken(user.id);
}

export async function createProject(_, { name, runtime, description }, { user }) {
    const validation = Joi.validate({ name, runtime, description }, CREATE_PROJECT_VALIDATION);

    if (validation.error) {
        throw new GraphQLError(validation.error.details[0].message);
    }

    const exists = await Project.findOne({ where: { name } });

    if (exists) {
        throw new GraphQLError('This project name is already used.');
    }

    const project = await Project.create({
        name,
        description,
        runtime: runtime.toLowerCase(),
        userId: user.id,
    });

    return project.serialize();
}

export async function updateProject(_, { id, description }) {
    const project = await Project.findById(id);
    project.description = description;
    await project.save();

    return project.serialize();
}

export async function deleteProject(_, { id }) {
    return Project.destroy({ where: { id } });
}

export async function uploadProject(_, { id, file }) {
    const [{ filename, stream }, project] = await Promise.all([
        file,
        Project.findById(id),
    ]);

    if (extname(filename) !== '.zip') {
        throw new GraphQLError('The file must be a zip.');
    }

    await Deployment.deploy(project, filename, stream);

    return project.serialize();
}
