class Solution {
public:

    int maxProfit(vector<int>& prices) {
        vector<int> actions = {-1,1,-1,1};
        vector<vector<int>> dp(prices.size()+1,vector<int>(5,0));
        for(int i=prices.size()-1;i>=0;i--){
            for(int j=actions.size()-1;j>=0;j--){
                        int first = prices[i]*actions[j] + dp[i+1][j+1];
                        int second =  dp[i+1][j];
                        dp[i][j]=max(first,second);
            }
        }
        return dp[0][0];
    }
};
