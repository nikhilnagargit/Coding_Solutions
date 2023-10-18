class Solution {
public:
   int mod=1e9+7;
   long long dp[51][102][102];
    int solve(int curr,int mx, int distinct,int n,int m,int k){
        if(curr==n){
            if(distinct==k){
                return 1;
            }
            return 0;
        }

        if(dp[curr][mx+1][distinct]!=-1){
            return dp[curr][mx+1][distinct];
        }

        long long ans=0;


        for(int i=1;i<=m;i++){
            int c1 = mx;
            int c2 = distinct;

            if(mx<i){
                c1 = i;
                c2 = distinct+1;
            }

            ans = ans + solve(curr+1,c1,c2,n,m,k);
        }
        return dp[curr][mx+1][distinct] = ans%mod;
    }
    
    int numOfArrays(int n, int m, int k) {
        memset(dp, -1, sizeof(dp));

        return solve(0,-1,0,n,m,k);
    }
};
