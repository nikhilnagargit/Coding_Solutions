class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0;
        int minimum = prices[0];
        for(int i=1;i<prices.size();i++){
            maxP = max(maxP, prices[i]-minimum);
            if(prices[i]<minimum){
                minimum = prices[i];
            }
        }
        return maxP;
    }
};
