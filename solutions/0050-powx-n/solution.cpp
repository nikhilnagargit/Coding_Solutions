class Solution {
public:
    double solve(double x, long n){
        if(x==0) return 0;
        if(n==0) return 1;
        if(n<0){
            return 1.0/solve(x,(-n));
        }
        // equalize this expression, so balanced tree is created while solving
        if(n%2==0){
            // even
            double half =  solve(x,n/2);
            return half*half;
        }
        // odd
        return  x * solve(x,n-1);
    }
    double myPow(double x, int n) {
        return solve(x,n);
    }
};
