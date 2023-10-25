/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let brr = [];
    for(let i=0;i<arr.length;i++){
        if(fn(arr[i],i)){
            brr.push(arr[i]);
        }
    }
    return brr;
};
