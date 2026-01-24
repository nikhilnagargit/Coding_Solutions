class Solution {
public:
    int solve(vector<int>& prices, int pi, vector<int>& transactions, int ti,vector<vector<int>> & dp){
        // all transactions completed
        if(ti==transactions.size() or pi==prices.size()){
            return 0;
        }
        if(dp[pi][ti]!=-1){
            return dp[pi][ti];
        }
    
        // make the transaction
        int a= prices[pi]*transactions[ti] + solve(prices,pi+1,transactions, ti+1,dp);
        // skip the transaction
        int b = solve(prices,pi+1,transactions,ti,dp);

        return dp[pi][ti]= max(a,b);
    }

    int maxProfit(int k,vector<int>& prices) {
        // -1 = buy , +1 = sell
        vector<int> transactions;
        for(int i=0;i<k;i++){
            transactions.push_back(-1);
            transactions.push_back(1);
        }
     
        vector<vector<int>> dp(prices.size(), vector<int>(transactions.size(),-1));
        return solve(prices,0,transactions,0,dp);
    }
};
