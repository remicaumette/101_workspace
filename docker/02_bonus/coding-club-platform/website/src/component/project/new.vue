<template>
    <v-layout align-start justify-center row fill-height>
        <v-flex xs12 sm6 md4>
            <v-card class="form">
                <v-card-title>
                    <span class="headline">Create new project</span>
                </v-card-title>

                <v-alert color="red darken-2" :value="error" type="error">
                    {{error}}
                </v-alert>

                <v-form @submit="submit">
                    <v-text-field color="blue accent-3" v-model="name" type="text" label="Name" required></v-text-field>
                    <v-select color="blue accent-3" v-model="runtime" :items="runtimes"
                        item-text="name" item-value="value" label="Runtime" required></v-select>
                    <v-textarea color="blue accent-3" v-model="description" label="Description"></v-textarea>
                    <v-btn type="submit" color="blue accent-3">Create</v-btn>
                    <v-btn flat @click="$router.go(-1)">Cancel</v-btn>
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
            runtimes: [
                { name: 'Static', value: 'STATIC' },
                { name: 'Node.js', value: 'NODEJS' },
                { name: 'PHP', value: 'PHP' },
            ],
            error: '',
            name: '',
            runtime: 'STATIC',
            description: '',
        };
    },
    methods: {
        async submit(event) {
            event.preventDefault();

            try {
                const { data: { createProject: { name } } } = await this.$apollo.mutate({
                    mutation: gql`
                        mutation ($name: String!, $runtime: Runtime!, $description: String) {
                            createProject(name: $name, runtime: $runtime, description: $description) {
                                name
                            }
                        }
                    `,
                    variables: {
                        name: this.name,
                        runtime: this.runtime,
                        description: this.description,
                    },
                });

                this.$router.push({ name: 'view_project', params: { name } });
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
