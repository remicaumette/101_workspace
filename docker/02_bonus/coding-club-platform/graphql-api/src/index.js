import signale from 'signale';
import database from './database';
import app from './app';
import userModel from './model/user';
import projectModel from './model/project';

signale.config({
    displayTimestamp: true,
    displayLabel: true,
    displayBadge: false,
});

userModel.hasMany(projectModel, { as: 'Projects' });

Promise.all([database.authenticate(), userModel.sync(), projectModel.sync()])
    .then(() => {
        if (process.env.NODE_ENV !== 'test') {
            app.listen(3000, () => {
                signale.info('Spring Camp Platform API started!');
                if (process.env.NODE_ENV !== 'production') {
                    signale.warn('If you are in production please set NODE_ENV to production');
                }
            });
        }
    })
    .catch((error) => {
        signale.fatal('Unable to connect to the database!');
        signale.fatal(error);
        process.exit(1);
    });
