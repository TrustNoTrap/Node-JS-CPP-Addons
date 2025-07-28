const testNative = require('./build/Release/test');
const testNativeTwo = require('./build/Release/testing');

console.log(
    testNative(1),
    testNative(5),
    testNative(10),
    testNative('s')
)

console.log(
    testNativeTwo.start('test')
)