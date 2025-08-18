class Solution {
public:
    int reverseBits(int n) {
        int res = 0;
        int mask = 1;
        for(int i=31;i>=0;i--){
            if(n&(1<<i)) res=res|mask;
            mask = mask<<1;
        }
        return res;
    }
};
