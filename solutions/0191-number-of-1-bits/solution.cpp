class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        for(int i=31;i>=0;i--){
            int mask = 1<<i;
            if((n&mask)){
                count++;
            }
        }
        return count;
    }
};
