const ffi        = require('ffi');
const ref        = require('ref');
const StructType = require('ref-struct');
const ArrayType  = require('ref-array');
console.log("beging to load lib...")

debugger
var libsadp = ffi.Library('../lib/print.so', {
		'myprint' : ['void', ['int', 'int']],
		'add' : ['int', ['int', 'int']],
});



