/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function(digits) {
 
    let target = digits.length-1;
    digits[target]+=1;
    let carry=0;
    while(target>=0){
        digits[target]+=carry;
        if(digits[target]<=9){
            return digits;
        }
        carry = Math.floor(digits[target]/10);
        digits[target] = digits[target]%10;

             target--;
    }
    if(carry){
        // add one element in array
        return [carry,...digits];
    }
    return digits;
    
};
