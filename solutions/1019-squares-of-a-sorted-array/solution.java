class Solution {
    public int[] sortedSquares(int[] nums) {
        int ans[] = new int[nums.length];
//         make square
        for(int i=0;i<nums.length;i++){
            nums[i] = nums[i]*nums[i];
        }
        
        int i=0;
        int j=nums.length-1;
        int c=nums.length-1;
        
        while(i<j){
            if(nums[i]>=nums[j]){
                ans[c] = nums[i];
                i++;
                c--;
            }
            else{
                ans[c] = nums[j];
                j--;
                c--;
            }
        }
        ans[0] = nums[i];
        return ans;
    }
}
