class Solution {
public:
    int find5factorcount(int n){
        int count = 0;
        while(n%5==0 and n!=0){
            n = n/5;
            count++;
        }
        return count;
    }
    int find2factorcount(int n){
        int count = 0;
        while(n%2==0 and n!=0){
            n = n/2;
            count++;
        }
        return count;
    }
    int trailingZeroes(int n) {
        int ans = 0;
        int a = 0;
        int b = 0;
        for(int i=n;i>=1;i--){
            a +=find5factorcount(i);
        }
        return a;
    }
};
