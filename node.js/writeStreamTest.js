var fs = require('fs');
var readStream = fs.createReadStream('./gift.mp3')
var out = fs.createWriteStream('./destBigFile.mp3')
readStream.on('data',(data) => {
		var flag = out.write(data);
		console.log(flag)
})

out.on('drain',() => {
		console.log("操作系统中的数据已经全部输出。")
})
