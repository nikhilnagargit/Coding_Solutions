class Solution {
public:
    long long getevencount(int n){
        return n/2;
    }
    long long getoddcount(int n){
        if(n%2==0){
            return n/2;
        }
        return n/2+1;
    }

    long long flowerGame(int n, int m) {
        long long a = getevencount(n);
        long long b = getoddcount(m);

        long long c = getevencount(m);
        long long d = getoddcount(n);
        return a*b + c*d;
    }
};
