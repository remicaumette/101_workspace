import { SchemaDirectiveVisitor } from 'graphql-tools';
import { GraphQLError } from 'graphql';

export default class Auth extends SchemaDirectiveVisitor {
    visitFieldDefinition(field) {
        const { args: { admin } } = this;
        const { resolve: defaultResolve } = field;

        field.resolve = function resolve(root, args, context, info) {
            if (!context.user) {
                throw new GraphQLError('User not authenticated.');
            }

            if (admin && !context.user.admin) {
                throw new GraphQLError('You are not allowed to do this action.');
            }

            return defaultResolve(root, args, context, info);
        };
    }
}
