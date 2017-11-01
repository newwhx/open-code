'use strict'

const router = require('koa-router')();
const bodyParser = require('koa-bodyparser')();
const Koa = require('koa');
const app = new Koa();

var fn_index = async (ctx, next) => {
		ctx.response.body = `<h1> Welcom to Koa2</h1>
				<form action='/login' method='post'>
				    <p>Name: <input name='name' value='koa'></p>
				    <p>Password: <input name='password', type='password'></p>
				    <p><input type='submit' value='Submit'></p>
				</form>`;
}

var fn_login = async (ctx, next) => {
		var name = ctx.request.body.name || '',
		    password = ctx.request.body.password || '';
		console.log(`login with name: ${name}, password: ${password}`);
		if (name == 'koa' && password == '12345') {
				ctx.response.body = `<h1> Welecom, ${name} to koa!</h1>`;
		}else{
				ctx.response.body = `<h1> Login failed! </h1>
				<p>Invalid username or password, <a href='/'> please try again</a></p>`;
		}
};

module.exports = {
		'GET /' : fn_index,
		'POST /login' : fn_login
};

