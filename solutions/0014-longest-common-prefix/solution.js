/**
 * @param {string[]} strs
 * @return {string}
 */
var check = function(str1,str2){
    let s = "";

    let i=0;
    while(i<str1.length && i<str2.length){
        if(str1[i]===str2[i]){
            s+=str1[i];
            i++
        }
        else{
            break;
        }
    }
    return s;
}

var longestCommonPrefix = function(strs) {
    if(strs.length===1){
        return strs[0];
    }
    let curr = strs[0];
    let i=1;
    while(i<strs.length){
        curr = check(curr,strs[i]);
        i++;
    } 
    return curr;
};
