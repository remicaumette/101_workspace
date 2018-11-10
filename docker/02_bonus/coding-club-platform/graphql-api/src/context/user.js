import { fatal } from 'signale';
import User from '../model/user';
import { getTokenContent } from '../utils/token';

export default async function ({ req }) {
    try {
        const token = req.headers.authorization;

        if (token) {
            const data = await getTokenContent(token);

            if (data) {
                const user = await User.findOne({ where: { id: data.user } });

                if (user) {
                    return user;
                }
            }
        }
    } catch (error) {
        fatal(error);
    }
}
