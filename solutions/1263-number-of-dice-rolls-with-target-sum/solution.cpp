class Solution {
public:
    int mod = 1000000007;
    int solve(int n,int k,int target,int i,vector<vector<int>>&dp){
        if(target>n*k){
            return 0;
        }
        if(i==n and target==0){
            return 1;
        }
        if(target<=0 or i>=n){
            return 0;
        }
        if(dp[i][target]!=-1){
            return dp[i][target];
        }
        int ans  = 0;
        for(int j=1;j<=k;j++){
            ans = (ans + solve(n,k,target-j,i+1,dp)%mod)%mod;
        }
        return dp[i][target] = ans%mod;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return solve(n,k,target,0,dp);
    }
};
