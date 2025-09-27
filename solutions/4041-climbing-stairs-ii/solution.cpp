class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1,0);
        dp[0]=0;
        if(n==0) return dp[0];
        
        dp[1]= costs[1-1]+1;
        if(n==1) return dp[1];
        
        dp[2]= min(dp[1]+costs[2-1]+1,dp[0]+costs[2-1]+4);
        if(n==2) return dp[2];
        
        for(int i=3;i<=n;i++){
            dp[i] = min({dp[i-3]+costs[i-1]+9,dp[i-2]+costs[i-1]+4,dp[i-1]+costs[i-1]+1});
        }
        return dp[n];
    }
};
