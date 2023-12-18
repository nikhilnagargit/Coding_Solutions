class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>dp(n+1,0);
        if(n==0) return dp;
        dp[1]= 1;
        if(n==1) return dp;
        
        for(int i=2;i<=n;i++){
            int lsb = 1 & i;
            if(lsb==1){
                dp[i] = dp[i>>1]+1;
            }
            else{
                dp[i] = dp[i>>1];
            }
        }
        return dp;
    }
};
