var testVar = "This is a variable from testModeule.js"
console.log(testVar);
exports.testVar = testVar;
if (module == require.main) {
		console.log("This is the main module of application");
}
