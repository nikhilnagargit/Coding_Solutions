class Solution {
public:
    int solve(vector<vector<int>>& matrix, int I,int J,vector<vector<int>>& dp){
        if(I<0 or I>=matrix.size() or J<0 or J>=matrix[0].size()){
            return INT_MAX;
        }
        if(dp[I][J]!=INT_MAX){
            return dp[I][J];
        }
        if(I==matrix.size()-1){
            return matrix[I][J];
        }
        return dp[I][J] = matrix[I][J] + min(solve(matrix,I+1,J-1,dp),min(solve(matrix,I+1,J,dp),solve(matrix,I+1,J+1,dp)));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        vector<vector<int>> dp(101,vector<int>(101,INT_MAX));
        for(int i=0;i<matrix[0].size();i++){
            ans = min(ans,solve(matrix,0,i,dp));
        }
        return ans;
    }
};
