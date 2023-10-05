/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
 
 var solve = function(nums,target,left,right){
     if(left===right && nums[left]===target){
    return left;
     }

     if(left===right && nums[left]<target){
         return left+1;
     }

     if(left===right && nums[left]>target){
         return left;
     }
    
    if(right>left){
     let mid = left+Math.floor((right-left)/2); 
     console.log(mid);

     if(nums[mid]===target){
         return mid;
     }
     if(nums[mid]<target){
         left = mid+1;
     }else{
         right = mid-1;
     }
     return solve(nums,target,left,right);
    }
    else{
        return left;
    }
     
 }

var searchInsert = function(nums, target) {
    let left = 0;
    let right = nums.length-1;
 return solve(nums,target,left,right)
};
