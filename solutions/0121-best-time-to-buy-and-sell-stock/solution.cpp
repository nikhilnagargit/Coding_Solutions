class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minValue = prices[0];
        for(auto& i:prices){
            minValue = min(minValue,i);
            maxProfit = max(maxProfit,i-minValue);
        }
        return maxProfit;
    }
};
