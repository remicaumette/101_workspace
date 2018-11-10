import Vue from 'vue';
import Vuex, { Store } from 'vuex';

Vue.use(Vuex);

export default new Store({
    state: {
        token: localStorage.getItem('token'),
    },
    mutations: {
        setToken(state, token) {
            state.token = token;
            localStorage.setItem('token', token);
        },
        removeToken(state) {
            state.token = undefined;
            localStorage.removeItem('token');
        },
    },
    getters: {
        token(state) {
            return state.token;
        },
        logged(state) {
            return !!state.token;
        },
    },
});
