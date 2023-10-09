/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    if(x<0){
        return false;
    }
    let x_backup = x;
    let x_rev = 0;
    while(x){
        x_rev = x_rev*10+x%10;
        x = Math.floor(x/10); 
    }
    if(x_rev==x_backup){
        return true;
    }
    return false;
};
