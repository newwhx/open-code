var fs = require('fs'); fs.watchFile('./message.txt', {persistent:true, interval:60*60*1000}, (curr, prev) => {
		console.log("======>\ncurr.ctime: " + curr.ctime + "\ncurr.mtime: " + curr.mtime + "\nprev.ctime: " + prev.mtime + "\nprev.mtime: " + prev.mtime + "\n<============")
		console.log("Date.parse(prev.ctime): " + Date.parse(prev.ctime))
		console.log("Date.parse(curr.ctime): " + Date.parse(curr.ctime))
		console.log("Date.parse(prev.mtime): " + Date.parse(prev.mtime))
		console.log("Date.parse(curr.mtime): " + Date.parse(curr.mtime))
		if ((Date.parse(prev.ctime) == 0) && (Date.parse(curr.ctime) != 0)) {
				console.log('file Message.txt is created.');
		}else if ((Date.parse(prev.ctime) != 0) && (Date.parse(curr.ctime) == 0)) {
				console.log('file Message.txt is deleted.')
		}else if (Date.parse(prev.mtime) != Date.parse(curr.mtime)) {
				console.log('file Message.txt is modified.')
		}
});
