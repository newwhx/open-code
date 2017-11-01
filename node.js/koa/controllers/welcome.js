'use strict'

var fn_welcome =  async(ctx, next) => {
		var name = ctx.params.name;
		ctx.response.body = '<h1> Hello '+ name + ' Welcome! </h1>';
};

module.exports = {
		'GET /hello/:name' : fn_welcome
};

