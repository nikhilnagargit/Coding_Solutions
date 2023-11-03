class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        int columns = obstacleGrid[0].size();

        vector<vector<int>>dp(rows,vector<int>(columns,0));

        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(i==0 and j==0 and obstacleGrid[i][i]!=1){
                    dp[i][j]=1;
                }
                else if(i==0 and obstacleGrid[i][j]!=1){
                    dp[i][j]=dp[i][j-1];
                }
                else if(j==0 and obstacleGrid[i][j]!=1){
                    dp[i][j]=dp[i-1][j];
                }
                else if(obstacleGrid[i][j]!=1){
                    dp[i][j] = dp[i-1][j]+dp[i][j-1];
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        return dp[rows-1][columns-1];
    }
};
