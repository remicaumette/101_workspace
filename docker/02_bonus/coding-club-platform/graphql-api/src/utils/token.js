import Jwt from 'jsonwebtoken';

export function createToken(id) {
    return new Promise((resolve, reject) => {
        Jwt.sign({ user: id, created_at: Date.now() }, process.env.SECRET || 'wowthisismysecret', (error, ok) => {
            if (error) {
                reject(error);
            } else {
                resolve(ok);
            }
        });
    });
}

export function getTokenContent(token) {
    return new Promise((resolve, reject) => {
        Jwt.verify(token, process.env.SECRET || 'wowthisismysecret', (error, data) => {
            if (error) {
                if (error.constructor.name === 'JsonWebTokenError') {
                    resolve(null);
                } else {
                    reject(error);
                }
            } else {
                resolve(data);
            }
        });
    });
}
