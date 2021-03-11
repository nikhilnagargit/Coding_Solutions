class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int local = 0;
        int optimal = 0;
        int i=-1;
        while(++i<nums.length){
            if(nums[i]==1){
                local+=1;
            }
            else{
                local=0;
            }
            if(local>optimal){
                optimal = local;
            }
        }
        
        return optimal;
    }
}
