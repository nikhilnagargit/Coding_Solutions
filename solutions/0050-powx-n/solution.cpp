class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        if(n==0){
            return 1;
        }
        if(x==1)
            return 1;

        if(x==-1)
            if(n%2==0) return 1;
            else return -1;

        if(n>0){
            while(n){
                ans = ans*x;
                n=n-1;
            }
            return ans;
        }

        while(n){
            ans = ans/x;
            if(abs(ans)<0.0000001) return 0;
            n=n+1;
        }
        return ans;
    }
};
