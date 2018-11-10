import Sequelize from 'sequelize';
import uuid from 'uuid';
import db from '../database';
import Deployment from '../deployment';

const Project = db.define('projects', {
    id: {
        type: Sequelize.UUID,
        defaultValue: uuid.v4,
        primaryKey: true,
    },
    name: {
        type: Sequelize.STRING,
    },
    description: {
        type: Sequelize.STRING,
    },
    runtime: {
        type: Sequelize.STRING,
    },
    ownerId: {
        type: Sequelize.UUID,
    },
}, {
    hooks: {
        async beforeDestroy(instance, options, cb) {
            await Deployment.destroy(instance);
            return cb();
        },
        async beforeBulkDestroy({ where }) {
            const projects = await Project.findAll({ where });
            await Promise.all(projects.map(Deployment.destroy));
        },
    },
});

Project.prototype.serialize = function serialize() {
    return {
        id: this.id,
        name: this.name,
        description: this.description,
        runtime: this.runtime.toUpperCase(),
        port: this.port,
        updatedAt: this.updatedAt,
        createdAt: this.createdAt,
    };
};

export default Project;
