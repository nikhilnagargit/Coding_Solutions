class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        int international_max   = 1;
        for(int i=1;i<nums.size();i++){
            int j = i-1;
            int maxi  = 1;
            while(j>=0){
                if(nums[j]<nums[i]){
                    maxi  = max(maxi,1+dp[j]);
                }
                j--;
            }
            dp[i] = maxi;
            international_max = max(international_max,maxi);
        }
        return international_max;
        
    }
};
