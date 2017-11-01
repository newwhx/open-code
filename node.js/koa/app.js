'use strict'

const Koa = require('koa');
const bodyParser = require('koa-bodyparser')();
const controller = require('./controller');
const nunjucks = require('nunjucks');
const app = new Koa();

function createEnv(path, opts){
    var autoescape = opts.autoescape === undefined ? true : opts.autoescape,
        noCache = opts.noCache || false,
        watch = opts.watch || false,
        throwOnUndefined = opts.throwOnUndefined || false,
        env = new nunjucks.Enviroment(
            new nunjucks.FileSystemLoader('view', {
                noCache : noCache,
                watch : watch,
            }),{
                atutoescape: autoescape,
                throwOnUndefined : throwOnUndefined
            }
        );
    if (opts.fileters){
        for (f in opts.fileters){
            env.addFilter(f,opts.filters[f]);
        }
    }

    return env;
}

var env = createEnv('view', {
    watch : true,
    filters:{
        hex: function (n){
            return '0x' + n.toString(16);
        }
    }
});

var s = env.render('hello.html', { name: '<script>alter("小明")</script>'});

app.use(bodyParser);
app.use(controller());

app.listen(3000);
console.log('app started at port 3000');
