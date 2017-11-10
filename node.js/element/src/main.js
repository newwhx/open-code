import Vue from 'vue'
import ElementUI from 'element-ui'
import 'element-ui/lib/theme-chalk/index.css'
import App from './App.vue'

Vue.use(ElementUI)

let tmp = new Vue({
  el: '#app',
  render: h => h(App)
})

Vue.use({tmp})
