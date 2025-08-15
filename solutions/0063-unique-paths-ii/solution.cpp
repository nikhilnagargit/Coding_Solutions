class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
         vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(i==0 and j==0){
                    if(grid[i][j]==1) dp[i][j]=0;
                    else dp[i][j]= 1;
                }
                else if(i==0){
                    if(grid[i][j]==1) dp[i][j]=0;
                    else dp[i][j]= dp[i][j-1];
                }
                else if(j==0){
                    if(grid[i][j]==1) dp[i][j]=0;
                    else dp[i][j]= dp[i-1][j];
                }
                else{
                    if(grid[i][j]==1) dp[i][j]=0;
                    else dp[i][j]= dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        return dp[grid.size()-1][grid[0].size()-1];

    }
};
