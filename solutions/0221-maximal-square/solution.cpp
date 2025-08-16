class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),0));
        int maxi = 0;
        for(int i=0;i<matrix.size();i++){
            dp[i][0]=0;
            if(matrix[i][0]=='1')
            dp[i][0]=1;
            maxi = max(maxi,dp[i][0]);
        }
        for(int j=0;j<matrix[0].size();j++){
            dp[0][j]=0;
            if(matrix[0][j]=='1')
            dp[0][j]=1;
            maxi = max(maxi,dp[0][j]);
        }
        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                if(matrix[i][j]=='1'){
                    dp[i][j] = 1 + min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]});
                }
                else{
                    dp[i][j] = 0;
                }
                maxi = max(maxi,dp[i][j]);
            }
        }
        return maxi*maxi;
    }
};
