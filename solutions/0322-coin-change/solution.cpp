class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,INT_MAX);
        dp[0]=0;

        for(int i=0;i<coins.size();i++){
            for(int j=1;j<=amount;j++){
                if(j-coins[i]>=0 and dp[j-coins[i]]!=INT_MAX){
                dp[j]=min(dp[j],1+dp[j-coins[i]]);
                }
            }
  
        }
        if(dp[amount]==INT_MAX){
            return -1;
        }
        return dp[amount];
    }
};
