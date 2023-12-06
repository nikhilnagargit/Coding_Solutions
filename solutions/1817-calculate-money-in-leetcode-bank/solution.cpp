class Solution {
public:
    int totalMoney(int n) {
        int week  = 0;
        int day = 1;
        int totalmoney = 0;
        int todaymoney = 1;
        while(7*week+day<=n){
            while(day<=7 and (7*week+day)<=n){
                totalmoney+= todaymoney;
                todaymoney++;
                day++;
            }
            week++;
            day = 1;
            todaymoney = week+1;
        }
        return totalmoney;
    }
};
