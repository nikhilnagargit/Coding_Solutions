class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX;
        int maxprofit = INT_MIN;
        for(int i=0;i<prices.size();i++){
            mini = min(mini,prices[i]);
            maxprofit = max(maxprofit,prices[i]-mini);
        }
        return maxprofit;
    }
};
