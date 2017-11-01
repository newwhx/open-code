http  = require('http');

server = http.createServer();
server.on('customEvent', function(arg1, arg2, arg3){
		console.log('custom  event ')
		console.log("%s", arg1, arg2, arg3);
});

server.emit('customEvent', '自定义参数1', '自定义参数2', '自定义参数3');

console.log('Server running at http://127.0.0.1:8888/');
