class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int filledBottles = numBottles;
        int emptyBottles = 0;
        int ans = 0;
        while(filledBottles){
            //drink
            emptyBottles+= filledBottles;
            ans+= filledBottles;
            filledBottles = emptyBottles/numExchange;
            emptyBottles = emptyBottles%numExchange;
        }
        return ans;
    }
};



// 15 -> 15/4 -> 3+3 -> 
