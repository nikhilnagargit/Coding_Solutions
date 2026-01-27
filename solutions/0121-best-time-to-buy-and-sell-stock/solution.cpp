class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPriceTillNow = prices[0];
        int maxProfit = 0;
        for(int i=0;i<prices.size();i++){
            if(minPriceTillNow>prices[i]){
                minPriceTillNow = prices[i];
            }
            maxProfit = max(maxProfit, prices[i]-minPriceTillNow);
        }
        return maxProfit;
    }
};
