class Solution {
public:
    int solve(vector<int>& nums,int left, int right,vector<vector<int>>& dp){
        if(left>right){
            return 0;
        }
        if(dp[left][right]!= -1) return dp[left][right];
        int prev = 1;
        if(left-1>=0)prev=nums[left-1];
        int next = 1;
        if(right+1<=nums.size()-1)next = nums[right+1];
        int maxi = 0;
        for(int i=left;i<=right;i++){
            //try to make this last bursted
            maxi = max(maxi, solve(nums,left,i-1,dp) + solve(nums,i+1,right,dp) + prev*nums[i]*next); 
        }
        return dp[left][right]=maxi;
    }
    int maxCoins(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),-1));
        return solve(nums,0,nums.size()-1,dp);
    }
};
