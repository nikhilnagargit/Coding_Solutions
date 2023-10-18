/**
 * @param {string} val
 * @return {Object}
 */
var expect = function(val) {
    function toBe(item){
        if(item===val)
        return true;
        else
        throw "Not Equal";
    }
    function notToBe(item){
           if(item!==val)
        return true;
        else
        throw "Equal";
    }
    return {toBe:toBe,notToBe:notToBe};
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */
