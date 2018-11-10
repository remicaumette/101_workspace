import BCrypt from 'bcrypt-nodejs';

export function comparePassword(password1, password2) {
    return new Promise((resolve, reject) => {
        BCrypt.compare(password1, password2, (error, ok) => {
            if (error) {
                reject(error);
            } else {
                resolve(ok);
            }
        });
    });
}

export function hashPassword(password) {
    return new Promise((resolve, reject) => {
        BCrypt.genSalt(10, (saltErr, salt) => {
            if (saltErr) {
                reject(saltErr);
            } else {
                BCrypt.hash(password, salt, undefined, (hashErr, hash) => {
                    if (hashErr) {
                        reject(hashErr);
                    } else {
                        resolve(hash);
                    }
                });
            }
        });
    });
}
