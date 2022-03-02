class Solution {
public:
    
    bool solve(vector<int>& nums, int i, vector<int>& dp){
        if(i==nums.size()-1){
            return 1;
        }
        
        if(nums[i]==0){
            return false;
        }
         
        for(int k=1;k<=nums[i];k++){
            if(dp[i+k]==-1){
                dp[i+k]= solve(nums,i+k,dp);
            }
            if(dp[i+k]==1){
                return 1;
            }
        }
        
        return 0;
    }
    
    
    bool canJump(vector<int>& nums) {        
        vector<int> dp(nums.size(),-1);
        dp[0] = 1;
        return solve(nums,0,dp);
    }
};
