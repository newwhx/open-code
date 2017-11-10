var foo = require('./foo.js')
var myfoo = new foo("Tom", 40);
console.log("before modify private var");
console.log(myfoo.GetName());
console.log(myfoo.GetAge());

console.log("after modify private var");
debugger
myfoo.SetName("Bob")
myfoo.SetAge(19)
console.log(myfoo.GetName());
console.log(myfoo.GetAge());


console.log("before modify public var");
console.log(myfoo.name)
console.log(myfoo.age)

myfoo.name = "Jim"
myfoo.age = 35
console.log("after modify public var");
console.log(myfoo.name)
console.log(myfoo.age)

console.log("after modify public var to see private var");
console.log(myfoo.GetName());
console.log(myfoo.GetAge());
