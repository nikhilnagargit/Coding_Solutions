class Solution {
public:

    int rangeBitwiseAnd(int left, int right) {
        if(left==0 or right==0) return 0;
        int a = (int)log2(left);
        int b = (int)log2(right);
        if(a!=b) return 0;
        long ans = left;
        for(long i=left;i<=right;i++){
            ans = ans&i;
        }
        return ans;
    }
};
