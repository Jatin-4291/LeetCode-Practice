// Last updated: 8/30/2025, 1:23:54 PM
/**
 * @return {Function}
 */
var createHelloWorld = function() {
    
    return function(...args) {
        const s="Hello World";
        return s;
    }
};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */