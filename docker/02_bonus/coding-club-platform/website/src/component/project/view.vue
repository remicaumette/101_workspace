<template>
    <v-layout align-start justify-center row fill-height>
        <v-flex sm12 md8 v-if="project">
            <v-card class="project">
                <v-card-title>
                    <span class="headline">{{project.name}}</span>

                    <v-spacer></v-spacer>

                    <v-menu bottom left>
                        <v-btn slot="activator" icon>
                            <v-icon>more_vert</v-icon>
                        </v-btn>

                        <v-list>
                            <v-list-tile :disabled="!project.url" @click="visit">
                                <v-list-tile-title>Visit</v-list-tile-title>
                            </v-list-tile>
                            <v-list-tile v-if="project.owner.id === me.id || me.admin" @click="edit = true">
                                <v-list-tile-title>Edit</v-list-tile-title>
                            </v-list-tile>
                        </v-list>
                    </v-menu>
                </v-card-title>

                <div class="description">
                    <p v-if="project.description">
                        {{project.description}}
                    </p>
                    <p v-else>
                        No description provided.
                    </p>
                </div>
                <v-divider></v-divider>
                <div class="owner">
                    <v-list-tile avatar>
                        <v-list-tile-avatar>
                            <img src="../../asset/avatar.png" />
                        </v-list-tile-avatar>
                        <v-list-tile-content>
                            <v-list-tile-title>
                                Created by <span :class="project.owner.admin ? 'admin' : ''">{{project.owner.username}}</span>
                            </v-list-tile-title>
                        </v-list-tile-content>
                    </v-list-tile>
                </div>
            </v-card>
        </v-flex>

        <v-dialog v-model="edit" fullscreen hide-overlay transition="dialog-bottom-transition" scrollable>
            <v-card tile>
                <v-toolbar card color="blue accent-3">
                    <v-btn icon @click="edit = false">
                        <v-icon>close</v-icon>
                    </v-btn>
                    <v-toolbar-title>Edit</v-toolbar-title>
                    <v-spacer></v-spacer>
                    <v-toolbar-items>
                        <v-btn flat @click="$refs.file.click()">Upload new version</v-btn>
                        <v-btn flat @click="saveProject">Save</v-btn>
                    </v-toolbar-items>
                </v-toolbar>
                <v-alert color="red darken-2" :value="error" type="error">
                    {{error}}
                </v-alert>
                <v-card-text>
                    <v-subheader>Settings</v-subheader>
                    <v-form>
                        <v-text-field color="blue accent-3" v-model="name" type="text" label="Name" required disabled></v-text-field>
                        <v-select color="blue accent-3" v-model="runtime" :items="runtimes"
                            item-text="name" item-value="value" label="Runtime" required disabled></v-select>
                        <v-textarea color="blue accent-3" v-model="description" label="Description"></v-textarea>
                        <input type="file" ref="file" hidden @change="newVersion"/>
                    </v-form>
                </v-card-text>
                <v-card-text>
                    <v-divider></v-divider>
                    <v-subheader>Danger zone</v-subheader>
                    <v-btn color="red darken-2" @click="deleteProject">Delete this project</v-btn>
                </v-card-text>
            </v-card>
        </v-dialog>
    </v-layout>
</template>

<script>
import gql from 'graphql-tag';

export default {
    data() {
        return {
            edit: false,
            runtimes: [
                { name: 'Static', value: 'STATIC' },
                { name: 'Node.js', value: 'NODEJS' },
                { name: 'PHP', value: 'PHP' },
            ],
            error: '',
            id: '',
            name: '',
            runtime: '',
            description: '',
        };
    },
    apollo: {
        project: {
            query: gql`
                query($name: String!) {
                    projectByName(name: $name) {
                        id
                        name
                        description
                        url
                        runtime
                        owner {
                            id
                            username
                            admin
                        }
                    }
                }
            `,
            variables() {
                return {
                    name: this.$route.params.name,
                };
            },
            update({ projectByName: project }) {
                this.id = project.id;
                this.name = project.name;
                this.runtime = project.runtime;
                this.description = project.description;

                return project;
            },
        },
        me: {
            query: gql`
                query {
                    me {
                        id
                        admin
                    }
                }
            `,
        },
    },
    methods: {
        async saveProject(event) {
            event.preventDefault();

            try {
                const { data: { updateProject: { name } } } = await this.$apollo.mutate({
                    mutation: gql`
                        mutation ($id: ID!, $description: String) {
                            updateProject(id: $id, description: $description) {
                                name
                            }
                        }
                    `,
                    variables: {
                        id: this.id,
                        description: this.description,
                    },
                });

                await this.$apollo.queries.project.refetch();
                this.edit = false;
            } catch (error) {
                if (error.graphQLErrors.length) {
                    this.error = error.graphQLErrors[0].message;
                } else {
                    this.error = error.message;
                }
            }
        },
        async newVersion() {
            try {
                await this.$apollo.mutate({
                    mutation: gql`
                        mutation ($id: ID!, $file: Upload!) {
                            uploadProject(id: $id, file: $file) {
                                url
                            }
                        }
                    `,
                    variables: {
                        id: this.id,
                        file: this.$refs.file.files[0],
                    },
                });

                await this.$apollo.queries.project.refetch();
                this.edit = false;
            } catch (error) {
                if (error.graphQLErrors.length) {
                    this.error = error.graphQLErrors[0].message;
                } else {
                    this.error = error.message;
                }
            }
        },
        async deleteProject() {
            try {
                await this.$apollo.mutate({
                    mutation: gql`
                        mutation ($id: ID!) {
                            deleteProject(id: $id)
                        }
                    `,
                    variables: {
                        id: this.id,
                        description: this.description,
                    },
                });
                this.$router.push({ name: 'home' });
            } catch (error) {
                if (error.graphQLErrors.length) {
                    this.error = error.graphQLErrors[0].message;
                } else {
                    this.error = error.message;
                }
            }
        },
        visit() {
            window.open(this.project.url, '_blank');
        },
    },
}
</script>
