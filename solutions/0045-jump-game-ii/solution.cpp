class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),999999);
        dp[0]=0;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<=nums[i]+i;j++){
                if(j<nums.size())
                dp[j] = min(dp[j],dp[i]+1);
            }
        }
        return dp[nums.size()-1];
    }
};
