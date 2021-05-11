class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int dp[101][101];
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        if(obstacleGrid[0][0]==0)
            dp[0][0] = 1;
        else
            return 0;
        
        for(int i=1;i<m;i++){
            if(obstacleGrid[i][0]==1){
                while(i<m){
                    dp[i][0] = 0;
                    i++;
                }
                break;
            }
             dp[i][0] = 1;
        }
        
        for(int i=1;i<n;i++){
            if(obstacleGrid[0][i]==1){
                while(i<n){
                    dp[0][i] = 0;
                    i++;
                }
                break;
            }
             dp[0][i] = 1;
        }
        
        
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]==1){
                    dp[i][j] =0 ;
                }
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                // cout<<dp[i][j]<<" ";
                
            }
            cout<<endl;
        }
        
        
        return dp[m-1][n-1];
        
        
        
    }
};
