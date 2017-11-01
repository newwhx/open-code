http  = require('http');

http.createServer(function (req, res){
		console.log(req.url);
		res.writeHead(200, {'Content-Type':'text/html'});
		res.write('<head><meta charset="utf-8"/></head>');
		res.end('Hell World\n');
}).listen(8888, "127.0.0.1");
/*
 * var http = require('http');
 * var server = http.createServer();
 * server.on('request', function(req, res){
 *     console.log(req.url);
 *     res.end();
 * });
 * server.listen(8888, "127.0.0.1");
 *
 * */
console.log('Server running at http://127.0.0.1:8888/');
