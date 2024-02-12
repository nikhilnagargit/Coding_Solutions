class Solution {
public:
    int dp[71][71][71];
    int solve(vector<vector<int>>& grid,int i,int j1,int j2){
        int m = grid.size();
        int n = grid[0].size();
        if(i==m){return 0;}
        if(j1<0 or j2<0 or j1>=n or j2>=n) return 0;
  
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];

        int ans = 0;
        for(int a=-1;a<2;a++){
            for(int b=-1;b<2;b++){
                ans = max(ans,solve(grid,i+1,j1+a,j2+b));
            }
        }
        if(j1!=j2)return dp[i][j1][j2]= ans+grid[i][j1]+grid[i][j2];
        return dp[i][j1][j2]=ans+grid[i][j1];
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return solve(grid,0,0,grid[0].size()-1);
    }
};
