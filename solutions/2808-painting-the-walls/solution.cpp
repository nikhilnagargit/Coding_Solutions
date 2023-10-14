class Solution {
public:

    int solve(vector<int>&cost,vector<int>&time, int start,int end,vector<vector<int>>&dp){
        if(end<=0){
            return 0;
        }
        if(start>= cost.size()){
            return 1e9;
        }

        if(dp[start][end]!=-1){
            return dp[start][end];
        }
        dp[start][end]= min(solve(cost,time,start+1,end,dp),cost[start]+solve(cost,time,start+1,end-time[start]-1,dp));
        return dp[start][end];

    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        vector<vector<int>> dp(501,vector<int>(501,-1));
        return solve(cost,time,0,cost.size(),dp);
    }
};
