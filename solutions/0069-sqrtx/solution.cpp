class Solution {
public:
    int mySqrt(int x) {
        long long res = 0;
        for(int i=31;i>=0;i--){
            //mask
            int mask = 1<<i;
            res = res|mask;
            if(res*res > x){
                res = res^mask;
            }
        }
        return res;
    }
};
