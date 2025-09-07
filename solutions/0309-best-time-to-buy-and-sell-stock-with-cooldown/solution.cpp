class Solution {
public:
    int solve(vector<int>& prices,int i,int action,vector<vector<int>>& dp){
        if(i==prices.size()){
            return 0;
        }
        if(dp[i][action]!=-1) return dp[i][action];
        int maxi = 0;
        //if action is to buy
        if(action==1){
            //next action will be sell
             maxi =  max(maxi,-1*prices[i]+solve(prices,i+1,2,dp));
        }
        //aciton is sell
        else if(action==2){
            // next action will be cooldown at least
               maxi = max(maxi, prices[i]+solve(prices,i+1,0,dp));
        }
        else if(action==0){
                maxi = max(maxi,solve(prices,i+1,1,dp));
        }
        //you can skip the day and take action later
        maxi = max(maxi,solve(prices,i+1,action,dp));

        return dp[i][action]=maxi;
    }
    int maxProfit(vector<int>& prices) {
        //actions 
        // 0 = cooldown
        // 1 = buy
        // 2 = sell
        vector<vector<int>> dp(prices.size(),vector<int>(3,-1));

        return solve(prices,0,1,dp);
    }
};
