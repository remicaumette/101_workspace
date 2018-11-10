import { ApolloServer } from 'apollo-server';
import { readdirSync, readFileSync } from 'fs';
import { join } from 'path';
import userContext from './context/user';
import * as resolvers from './resolvers';
import * as schemaDirectives from './directives';

const SCHEMA_DIR = join(__dirname, '..', 'schema');

export default new ApolloServer({
    typeDefs: readdirSync(SCHEMA_DIR)
        .map(file => readFileSync(join(SCHEMA_DIR, file), 'utf8')),
    resolvers,
    schemaDirectives,
    debug: true,
    async context(ctx) {
        return {
            user: await userContext(ctx),
        };
    },
});
