class Solution {
public:
    unordered_map<string,int>dp;
    int solve(vector<int>& prices,int& fee,int action,int i){
        string s = to_string(action)+"-"+to_string(i);
        if(dp.find(s)!=dp.end()){
            return dp[s];
        }
        if(i==prices.size()-1 and action==-1){
            return prices[i]-fee;
        }
        if(i==prices.size()-1 and action==1){
            return 0;
        }
        int result = solve(prices,fee,action,i+1);
        // buy 
        if(action==1){
            result = max(result,solve(prices,fee,-1,i+1)-prices[i]);
        }
        // sell
        else if(action==-1){
            result = max(result,solve(prices,fee,1,i+1)+prices[i]-fee);
        }
        // do nothing
        
        dp[s]=result;
        return result;
    }
    int maxProfit(vector<int>& prices, int fee) {
        return solve(prices,fee,1,0);
    }
};
