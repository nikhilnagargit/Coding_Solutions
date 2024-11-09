class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i=n;i<=100000;i++){
            int mul = 1;
            int N = i;
            while(N){
                int digit = N%10;
                mul = mul*digit;
                N = N/10;
            }
            if(mul%t==0){
                return i;
            }
            
        }
        return 0;
    }
};
