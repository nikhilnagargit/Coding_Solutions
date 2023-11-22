class Solution {
public:
    
    int solve(vector<int>&prices, int rem_transaction,int day,vector<vector<int>>& m){
        if(m[rem_transaction][day]!=-1)return m[rem_transaction][day];

        if(rem_transaction==0){
            return 0;
        }
        if(day>=prices.size()) return 0;
        // include current day in transaction
        int ans1 ;
        if(rem_transaction%2==0){
            ans1 = -prices[day]+solve(prices,rem_transaction-1,day+1,m);
        }
        else{
            ans1 = prices[day] + solve(prices,rem_transaction-1,day+1,m);
        }
        // exclude current day in transaction
        int ans2 = solve(prices,rem_transaction,day+1,m);
        m[rem_transaction][day] = max(ans1,ans2);
        return m[rem_transaction][day];
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>m(5,vector<int>(prices.size()+1,-1));
        int rem_transaction = 4;
        int curr_index = 0;
        return solve(prices,rem_transaction,curr_index,m);
    }
};
