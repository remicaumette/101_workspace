<template>
    <v-layout align-start justify-center row fill-height>
        <v-flex xs12 sm6 md4>
            <v-card class="form">
                <h1>Login</h1>

                <v-alert color="red darken-2" :value="error" type="error">
                    {{error}}
                </v-alert>

                <v-form @submit="submit">
                    <v-text-field color="blue accent-3" v-model="email" type="email" label="Email" required></v-text-field>
                    <v-text-field color="blue accent-3" v-model="password" type="password" label="Password" required></v-text-field>
                    <v-btn type="submit" color="blue accent-3">Login</v-btn>
                    <v-btn flat :to="{ name: 'register' }">Register</v-btn>
                </v-form>
            </v-card>
        </v-flex>
    </v-layout>
</template>

<script>
import gql from 'graphql-tag';

export default {
    data() {
        return {
            email: '',
            password: '',
            error: '',
        };
    },
    methods: {
        async submit(event) {
            event.preventDefault();

            try {
                const { data: { createToken: token } } = await this.$apollo.mutate({
                    mutation: gql`
                        mutation ($email: String!, $password: String!) {
                            createToken(email: $email, password: $password)
                        }
                    `,
                    variables: {
                        email: this.email,
                        password: this.password,
                    },
                });

                this.$store.commit('setToken', token);
                this.$router.push({ name: 'home' });
            } catch (error) {
                if (error.graphQLErrors.length) {
                    this.error = error.graphQLErrors[0].message;
                } else {
                    this.error = error.message;
                }
            }
        },
    },
}
</script>
