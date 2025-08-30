class Solution {
public:
    //dir , 1 = top to down , 0 = left to right
    int MOD = 1000000007;
    int solve(vector<vector<int>>& grid,int i,int j,int dir,vector<vector<vector<int>>>&dp){
        if(i==grid.size()-1 and j==grid[0].size()-1){
            return 1;
        }
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size()){
            return 0;
        }
        if(dp[i][j][dir]!=-1) return dp[i][j][dir];
        //there is mirror
        if(grid[i][j]==1){
            //top to down
            if(dir==1){
                return dp[i][j][dir]= solve(grid,i,j+1,0,dp)%MOD;
            }
            else{
                //left to right
                return dp[i][j][dir]= solve(grid,i+1,j,1,dp)%MOD;
            }
        }
            //there is no mirror, go both sides

           return dp[i][j][dir]= (solve(grid,i,j+1,0,dp)%MOD +solve(grid,i+1,j,1,dp)%MOD)%MOD;

    }
    int uniquePaths(vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(2,-1)));
        return solve(grid,0,0,0,dp)%MOD;
    }
};
