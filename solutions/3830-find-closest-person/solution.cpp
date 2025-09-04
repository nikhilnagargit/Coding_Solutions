class Solution {
public:
    int findClosest(int x, int y, int z) {
        int xdis = abs(z-x);
        int ydis = abs(z-y);
        if(xdis<ydis) return 1;
        else if(xdis==ydis) return 0;
        return 2;
    }
};
