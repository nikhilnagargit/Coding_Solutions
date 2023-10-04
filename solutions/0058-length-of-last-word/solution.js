/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
 

return s.split(' ').filter(w => w!=='').at(-1).length;

};
