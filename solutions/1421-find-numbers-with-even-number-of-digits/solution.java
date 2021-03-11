class Solution {
    public int findNumbers(int[] nums) {
        int ans=0;
        int digits = 0;
        for(int num:nums){
            while(num>0){
                num = num/10;
                digits++;
            }
            if(digits%2==0){
                ans++;
            }
            digits=0;
        }
        return ans;
    }
}
