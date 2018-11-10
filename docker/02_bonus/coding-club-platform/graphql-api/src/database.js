import Sequelize from 'sequelize';
import path from 'path';

export default process.env.NODE_ENV === 'production' ?
    new Sequelize(process.env.DB_URI, { operatorsAliases: false, logging: false }) :
    new Sequelize({
        dialect: 'sqlite',
        operatorsAliases: false,
        storage: process.env.NODE_ENV === 'test' ? ':memory:' : path.join(__dirname, '..', 'data', 'database.db'),
        logging: false,
    });
