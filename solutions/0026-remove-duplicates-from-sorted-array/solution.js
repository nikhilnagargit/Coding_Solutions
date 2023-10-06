/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    let p = 0;
    let i = 1;
    while(i<=nums.length){
        if(nums[i]!==nums[i-1]){
            p++;
            nums[p] = nums[i]; 
        }
        i++;
    }
    return p;
};
