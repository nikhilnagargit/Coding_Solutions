class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if((abs(fx-sx)==0 and abs(fy-sy)==0) and t==1)return false;
        return t>=max(abs(fx-sx),abs(fy-sy));
    }
};
