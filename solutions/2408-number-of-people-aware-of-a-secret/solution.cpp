class Solution {
public:
    int MOD = 1000000007;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> v(forget,0);
        v[forget-1] = 1;
        int sum = 0;
        int day = 1;
        while(day<n){
            int activesum = 0;
            for(int i=1;i<forget;i++){
                    v[i-1]=v[i];
                    if(i-1<(forget-delay)){
                        activesum = (activesum+v[i-1])%MOD;
                    }
            }
            v[forget-1] = activesum;
            day++;
        }
        //sum
        for(int i=0;i<forget;i++){
            sum = (sum+v[i])%MOD;
        }
        return sum;
    }
};
