class Solution {
public:
    vector<string> actions = {"buy","sell","buy","sell"};
    int solve(vector<int>& prices, int i,int a,vector<vector<int>>& dp){
        
        if(i==prices.size() or a==actions.size())return 0;

        if(dp[i][a]!=-1) return dp[i][a];

        if(actions[a]=="buy"){
            int ans = INT_MIN;
            //buy current and move to next for selling
            ans = max(ans,solve(prices,i+1,a+1,dp)-prices[i]);
            //don't buy move to next to buy
            ans = max(ans,solve(prices,i+1,a,dp));
            return dp[i][a]=ans;
        }
        else{
            int ans = INT_MIN;
            //sell current and move next to buy
            ans = max(ans,solve(prices,i+1,a+1,dp)+prices[i]);
            //dont' sell  move next to sell
            ans = max(ans,solve(prices,i+1,a,dp));
            return dp[i][a]=ans;
        }
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(actions.size(),-1));
        return solve(prices,0,0,dp);
    }
};
