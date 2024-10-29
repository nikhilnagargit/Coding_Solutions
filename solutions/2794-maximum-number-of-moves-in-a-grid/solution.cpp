class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),0));
        int M = grid.size();
        int N = grid[0].size();
        int maxi = 0;
        for(int i=0;i<grid.size();i++){
            dp[i][0] =1;
        }

        for (int j = 1; j < N; j++) {
            for (int i = 0; i < M; i++) {


                if (grid[i][j] > grid[i][j - 1] && dp[i][j - 1] > 0) {
                    dp[i][j] = max(dp[i][j], dp[i][j - 1] + 1);
                }
                if (i - 1 >= 0 && grid[i][j] > grid[i - 1][j - 1] &&
                    dp[i - 1][j - 1] > 0) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                }
                if (i + 1 < M && grid[i][j] > grid[i + 1][j - 1] &&
                    dp[i + 1][j - 1] > 0) {
                    dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + 1);
                }

                maxi = max(maxi,dp[i][j]-1);
            
            }
        }

        return maxi;
    }
};
