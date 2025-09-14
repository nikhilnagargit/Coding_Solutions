class Solution {
public:
int MOD = 1e9+7;
    int solve(vector<int>& nums,int last,int secondlast, int curr, vector<vector<vector<int>>>&dp){
        if(curr==nums.size()) return 1;
        //take it not take it
        if(dp[curr][last][secondlast]!=-1){
            return dp[curr][last][secondlast];
        }
        int total = 0;
         if(nums[curr]%2==0){
            if(last!=0 or secondlast!=0){
                total += solve(nums,0,last,curr+1,dp)%MOD;
            }
            total+= solve(nums,last,secondlast,curr+1,dp)%MOD;
         }
         else{
            if(last!=1 or secondlast!=1){
                total+= solve(nums,1,last,curr+1,dp)%MOD;
            }
            total+= solve(nums,last,secondlast,curr+1,dp)%MOD;
         }
         return dp[curr][last][secondlast]=(total)%MOD;
    }

    int countStableSubsequences(vector<int>& nums) {
        // 0 = even, 1 = odd
        vector<vector<vector<int>>> dp(nums.size()+1,vector<vector<int>>(3,vector<int>(3,-1)));
        int ans =  solve(nums,2,2,0,dp)%MOD;  
        return ans-1;
    }
};
