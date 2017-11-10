var addon = require('bindings')('addon');

addon(function(msg){
		console.log(msg);
		console.log(msg[0]);
		console.log(msg[1]);
});
