class Solution {
public:
    int solve(vector<int>& nums,int i,int maxor,int curror,  vector<vector<int>>& dp){
        if(i>=nums.size()){
            if(maxor==curror){
               return 1;
            }
            return 0 ;
        }
        if(dp[i][curror]!=-1){
            return dp[i][curror];
        }
        // take it
        int a = solve(nums,i+1,maxor,curror|nums[i],dp);
        //dont take it stop there
        int b = solve(nums,i+1,maxor,curror,dp);

        return dp[i][curror] =  a+b;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int maxor = 0;
        for(auto& n: nums) maxor= maxor|n;
        int i=0;
        int curror =0;
        int count= 0;
        vector<vector<int>> dp(nums.size()+1,vector<int>(maxor+1,-1));

        return solve(nums,i,maxor,curror,dp);

    }
};
