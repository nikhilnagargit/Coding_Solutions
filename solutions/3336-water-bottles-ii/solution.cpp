class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int emptyBottles = 0;
        int fullBottles = numBottles;
        int drunkBottles = 0;
        while(numExchange<=(emptyBottles+fullBottles)){
            //drink full bottles
            emptyBottles+= fullBottles;
            drunkBottles+= fullBottles;
            fullBottles = 0;

            //exchange and increase
            fullBottles+= 1;
            emptyBottles-= numExchange;
            numExchange++;
        }
        drunkBottles+= fullBottles;
        
        return drunkBottles;
    }
};
