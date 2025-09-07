class Solution {
public:
    bool isvalid(vector<vector<int>>& matrix,int i,int j){
        if(i<0 or j<0 or i>=matrix.size() or j>=matrix[0].size()){
            return false;
        }
        return true;
    }

    int solve(vector<vector<int>>& matrix, int i,int j,vector<vector<int>>& dp){
        int a=0,b=0,c=0,d=0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(isvalid(matrix,i+1,j) and matrix[i][j]<matrix[i+1][j]){
            a=solve(matrix,i+1,j,dp);
        }
        if(isvalid(matrix,i-1,j) and matrix[i][j]<matrix[i-1][j]){
            b=solve(matrix,i-1,j,dp);
        }
        if(isvalid(matrix,i,j+1) and matrix[i][j]<matrix[i][j+1]){
            c=solve(matrix,i,j+1,dp);
        }
        if(isvalid(matrix,i,j-1) and matrix[i][j]<matrix[i][j-1]){
            d=solve(matrix,i,j-1,dp);
        }
        return dp[i][j]=1+max({a,b,c,d});
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        //perform dfs for each cell and track longest path found
        //any optimizations?
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),-1));
        int maxi = 0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                maxi = max(maxi,solve(matrix,i,j,dp));
            }
        }
        return maxi;
    }
};
