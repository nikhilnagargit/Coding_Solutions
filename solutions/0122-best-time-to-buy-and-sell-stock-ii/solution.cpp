class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int localProfit = 0;
        int globalProfit = 0;

        for(int i=1;i<prices.size();i++){
            if(prices[i-1]>prices[i]){
                globalProfit += localProfit;
                localProfit = 0;
            }
            else{
                localProfit += prices[i]-prices[i-1];
            }
        }
        globalProfit += localProfit;

        return globalProfit;
    }
};
