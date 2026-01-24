class Solution {
public:
    int solve(vector<int>& prices,int i,int action,unordered_map<string,int>& m){
        if(i==prices.size()){
            return 0;
        }
        string key = to_string(i) + '-' + to_string(action);
        if(m.find(key)!=m.end()){
            return m[key];
        }

        // cooldown
        if(action==0){
            // set next action to buy and skip current stock
            return m[key]=solve(prices,i+1,-1,m);
        }

        // buy
        if(action==-1){
            //skip buy or buy right now
            return m[key]= max(solve(prices,i+1,-1,m),-prices[i]+solve(prices,i+1,1,m));
        }

        //sell
        if(action==1){
            //skip sell or sell right now
            return m[key]= max(solve(prices,i+1,1,m),prices[i]+solve(prices,i+1,0,m));
        }
        return 0;
    }

    int maxProfit(vector<int>& prices) {
    // buy = -1
    // sell = 1
    // cooldown =0
    unordered_map<string,int> m;
    return solve(prices, 0, -1, m);
    }
};
