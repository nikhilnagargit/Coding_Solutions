/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    let v = [];
    for(let i=0;i<arr.length;i++){
        v.push(fn(arr[i],i));
    }
    return v;
};
