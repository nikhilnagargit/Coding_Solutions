/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function(nums, val) {
    let limit = nums.length;
    let i = 0;
    while(i<limit){
    
        if(nums[i]===val){
            let j = i;
            while(j<limit-1){
                nums[j] =nums[j+1];
                j++;
            }
            limit--;
        }
        else{
        i++;
        }
    }
    return limit;
};
