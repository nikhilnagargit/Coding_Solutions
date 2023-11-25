class Solution {
private:
    vector<int> dp;
    int F(int i,vector<int> &prices){
        int n = prices.size();
        if(i >= prices.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int minCoins = 1e9;
        for(int j=0;j<=min(n,(i+1));j++) 
            minCoins = min(minCoins,F(j+i+1,prices));
        return dp[i] = prices[i] + minCoins;
    }
public:
    int minimumCoins(vector<int>& prices){
        dp= vector<int>(1005,-1);
        return F(0,prices);
    }
};
