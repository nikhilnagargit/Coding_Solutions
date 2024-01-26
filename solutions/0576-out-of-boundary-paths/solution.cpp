class Solution {
public:
    int dp [51][51][51];
    int mod = 1000000007;
    int solve(int& m,int& n,int rem_moves,int i,int j){
        if(i<0 or j<0 or i>=m or j>=n){
            return 1;
        }
        if(rem_moves<=0){
            return 0;
        }
        if(dp[i][j][rem_moves]!=-1){
            return dp[i][j][rem_moves];
        }
        int a = solve(m,n,rem_moves-1,i+1,j)%mod;
        int b = solve(m,n,rem_moves-1,i,j+1)%mod;
        int c = solve(m,n,rem_moves-1,i,j-1)%mod;
        int d = solve(m,n,rem_moves-1,i-1,j)%mod;
        return dp[i][j][rem_moves]= ((((a+b)%mod+c)%mod)+d)%mod;
    }
    int findPaths(int m, int n34, int maxMove, int startRow, int startColumn) {
        int n = 51;
for (int in1=0; in1<n; in1++)            
    for (int in2=0; in2<n; in2++)      
        for (int in3=0; in3<n; in3++)  
            dp[in1][in2][in3] = -1;
        return solve(m,n34,maxMove,startRow,startColumn);
    }
};
