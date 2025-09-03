class Solution {
public:
    int solve(vector<int>& nums,int left, int right){
        int n = right-left+1;
        vector<int> dp(n,0);
        if(n==0) return 0;
        dp[0]=nums[left];
        if(n==1) return dp[0];
        dp[1] = max(nums[left+1],dp[0]);
        if(n==2) return max(dp[0],dp[1]);
        for(int i=2;i<n;i++){
            dp[i]= max(dp[i-1],dp[i-2]+nums[left+i]);
        }
        return dp[n-1];
    }
 
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0){
            return 0;
        }
        if(n==1){
            return nums[0];
        }
        if(n==2){
            return max(nums[0],nums[1]);
        }
  
        return max(solve(nums,0,n-2),solve(nums,1,n-1));
    }
};
