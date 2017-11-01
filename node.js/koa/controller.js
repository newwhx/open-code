'use strict'
const fs = require('fs');

function addMapping(router, mapping){
		for (var url in mapping) {
				if (url.startsWith('GET')) {
						var path = url.substring(4);
						router.get(path, mapping[url]);
						console.log(`register URL mapping: GET ${path}`);
				}else if (url.startsWith('POST')) {
						var path = url.substring(5);
								router.post(path, mapping[url]);
								console.log(`register URL mapping: POST ${path}`);
						}else{
								console.log(`Invalid URL: ${url}`);
						}
		}
}

function addController(router, dir){
		var path = __dirname + '/' + dir;
		console.log(`dir path: ${path}`);
		var js_files = fs.readdirSync(path).filter((f) => {
				return f.endsWith('.js');
		});

		for (var f of js_files) {
				console.log(`process controller: ${f}`);
				let mapping = require(path + '/' + f);
				console.log(mapping);
				addMapping(router, mapping);
		}

}

module.exports = function(dir){
		let controller_dir = dir || 'controllers',
			router = require('koa-router')();
		addController(router, controller_dir);
		return router.routes();
};
