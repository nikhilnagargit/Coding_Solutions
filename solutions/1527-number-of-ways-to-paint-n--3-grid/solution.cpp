class Solution {
public:
    int solve(int n, vector<int>& prev, vector<vector<vector<vector<int>>>>& dp){
        if(n==0) return 1;
        int ans = 0;
        if(dp[n][prev[0]+1][prev[1]+1][prev[2]+1]!=-1) return dp[n][prev[0]+1][prev[1]+1][prev[2]+1];
        vector<int> curr (3,0);
        for(int color = 0;color<3;color++){
            if(color==prev[0]){
                continue;
            }
            curr[0]=color;
            for(int color1 = 0;color1<3;color1++){
                if(color1==curr[0] or color1==prev[1]){
                    continue;
                }
                curr[1]=color1;
                for(int color2 = 0;color2<3;color2++){
                    if(color2==curr[1] or color2==prev[2]){
                        continue;
                    }
                    curr[2]=color2;
                    ans = (ans + solve(n-1,curr,dp)%1000000007)%1000000007; 
                }
            }
        }
        return dp[n][prev[0]+1][prev[1]+1][prev[2]+1]=ans;
    }
    int numOfWays(int n) {
        vector<int> prev(3,-1);
        vector<vector<vector<vector<int>>>> dp(n+1,vector<vector<vector<int>>>(4, vector<vector<int>>(4,vector<int>(4,-1))));
        return solve(n,prev,dp);
    }
};
