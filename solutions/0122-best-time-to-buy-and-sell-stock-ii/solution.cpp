class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prev = prices[0];
        int curr;
        int max_profit = 0;
        for(int i=1;i<prices.size();i++){
            curr = prices[i];
            if(curr>prev){
                max_profit += curr-prev;
            }
            prev = curr;
        }
        return max_profit;
    }
};
