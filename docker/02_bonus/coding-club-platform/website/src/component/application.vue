<template>
    <v-app dark>
        <v-toolbar color="blue accent-3" style="margin-bottom: 30px;">
            <v-toolbar-title style="width: 300px" class="ml-0">
                <span @click="home">Coding Club Platform</span>
            </v-toolbar-title>

            <v-spacer></v-spacer>

            <div v-if="$store.getters.logged">
                <v-btn icon :to="{ name: 'new_project' }">
                    <v-tooltip bottom>
                        <v-icon slot="activator">add</v-icon>
                        <span>Create new project</span>
                    </v-tooltip>
                </v-btn>
                <v-btn icon @click="logout">
                    <v-tooltip bottom>
                        <v-icon slot="activator">exit_to_app</v-icon>
                        <span>Logout</span>
                    </v-tooltip>
                </v-btn>
            </div>
        </v-toolbar>

        <router-view></router-view>
    </v-app>
</template>

<script>
export default {
    methods: {
        logout() {
            this.$store.commit('removeToken');
            this.$router.push({ name: 'login' });
        },
        home() {
            if (this.$store.getters.logged) {
                this.$router.push({ name: 'home' });
            } else {
                this.$router.push({ name: 'login' });
            }
        },
    },
}
</script>
