var fs = require('fs');
var file = fs.createReadStream('./message.txt', 'utf-8');

file.on('data', (data) => {
		console.log('get the data: ');
console.log(data);
});

file.on('error', (err) => {
		console.log('read file fail....');
});

file.on('end', () =>{
		console.log('all data has been got')
})

file.on('close', () => {
		console.log('file is closed')
})


