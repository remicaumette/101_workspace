import Vue from 'vue';
import VueApollo from 'vue-apollo';
import { ApolloClient } from 'apollo-client';
import { createUploadLink } from 'apollo-upload-client';
import { InMemoryCache } from 'apollo-cache-inmemory';
import { ApolloLink, concat } from 'apollo-link';
import App from '.';

Vue.use(VueApollo);

export default new VueApollo({
    defaultClient: new ApolloClient({
        link: concat(
            new ApolloLink((operation, forward) => {
                operation.setContext({
                    headers: {
                        Authorization: App.$store.getters.token,
                    },
                });
                return forward(operation);
            }),
            createUploadLink({
                uri: 'http://192.168.99.100:3000',
            }),
        ),
        cache: new InMemoryCache(),
        connectToDevTools: true,
    }),
    defaultOptions: {
        $query: {
            fetchPolicy: 'network-only',
        },
    },
});
