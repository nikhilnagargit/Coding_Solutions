class Solution {
public:

    bool canPartition(vector<int>& nums) {
        int total_sum = accumulate(nums.begin(),nums.end(),0);
        if(total_sum%2!=0){
            return false;
        }
        int s = nums.size()+1;

        vector<vector<int>> dp( s , vector<int> (total_sum/2+1, 0));
        
        for(int i=0;i<s;i++){
            dp[i][0] = 1;
        }
        
        for(int i=1;i<s;i++){
            for(int j=1;j<total_sum/2+1;j++){
                if(dp[i-1][j]==1){
                    dp[i][j] = 1;
                }
                else if(j>=nums[i-1]){
                    dp[i][j] = dp[i-1][j-nums[i-1]];
                }
                else{
                    
                }
            }
        }
        
        return dp[s-1][total_sum/2];
        
    }
};
