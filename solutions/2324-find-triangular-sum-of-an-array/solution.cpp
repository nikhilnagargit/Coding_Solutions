class Solution {
public:
    int triangularSum(vector<int>& nums) {
        vector<int> dp = nums;
        
        while(dp.size()!=1){
        vector<int> temp;
        for(int i=0;i<dp.size()-1;i++){
            temp.push_back((dp[i]+dp[i+1])%10);
        }
        dp = temp;
        }
        return dp[0];
    }
};
