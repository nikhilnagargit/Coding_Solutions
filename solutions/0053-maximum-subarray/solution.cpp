#include<algorithm>

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int dp[300001];
        memset(dp,0,300001);
        
        dp[0] = nums[0];
        
        for(int i =1;i<nums.size();i++){
            int value1 = dp[i-1] + nums[i];
            int value2 = nums[i];
            int v = max(value1,value2);
            dp[i] = v;
        }
        
        return *(max_element(dp,dp+nums.size()));
  
    }
    
};
