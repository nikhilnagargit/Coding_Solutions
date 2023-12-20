class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int minimum;
        int secondminimum;
        if(prices.size()<2){
            return money;
        }
        if(prices[0]<prices[1]){
            minimum = prices[0];
            secondminimum = prices[1];
        }
        else{
            minimum = prices[1];
            secondminimum = prices[0];
        }
        for(int i=2;i<prices.size();i++){
            if(prices[i]<minimum){
                secondminimum = minimum;
                minimum = prices[i];
            }
            else if(prices[i]<secondminimum){
                secondminimum = prices[i];
            }
        }
        if(minimum+secondminimum<=money){
            return money-minimum-secondminimum;
        }
        else{
            return money;
        }
    }
};
