import Vue from 'vue';
import VueRouter from 'vue-router';
import Home from './component/home.vue';
import NewProject from './component/project/new.vue';
import ViewProject from './component/project/view.vue';
import Register from './component/register.vue';
import Login from './component/login.vue';

Vue.use(VueRouter);

const router = new VueRouter({
    mode: 'history',
    routes: [
        { name: 'home', path: '/home', component: Home },
        { name: 'new_project', path: '/project/new', component: NewProject },
        { name: 'view_project', path: '/project/:name', component: ViewProject },
        { name: 'register', path: '/register', component: Register },
        { name: 'login', path: '/login', component: Login },
    ],
});

const AUTH_ROUTES_NAME = ['login', 'register'];

router.beforeEach((to, from, next) => {
    if (router.app.$store.getters.logged) {
        if (AUTH_ROUTES_NAME.includes(to.name) || !to.name) {
            next({ name: 'home' });
        } else {
            next();
        }
    } else {
        if (AUTH_ROUTES_NAME.includes(to.name)) {
            next();
        } else {
            next({ name: 'login' });
        }
    }
});

export default router;
