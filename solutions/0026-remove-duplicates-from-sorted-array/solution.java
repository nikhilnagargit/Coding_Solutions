class Solution {
    public int removeDuplicates(int[] nums) {
        if(nums==null || nums.length==0){
            return 0;
        }
        int i =0,j=1;
        int prev = nums[0];
        while(i<nums.length){
            if(prev!=nums[i]){
                prev = nums[i];
                nums[j] = nums[i];

                j++;
            }
                i++;
        }
      return j;
    }
}
