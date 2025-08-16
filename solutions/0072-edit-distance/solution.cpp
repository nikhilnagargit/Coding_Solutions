class Solution {
public:
    int solve(string& word1, string& word2, int i,int j,vector<vector<int>>& dp){
        if(i==word1.size()) return word2.size()-j;
        if(j==word2.size()) return word1.size()-i;
        if(dp[i][j]!=-1) return dp[i][j];
        int min_cost = INT_MAX;
        if(word1[i]==word2[j]){
            min_cost = min(min_cost,solve(word1,word2,i+1,j+1,dp));
        }
        else{
            min_cost = min(min_cost,1+solve(word1,word2,i+1,j+1,dp));
            min_cost = min(min_cost,1+solve(word1,word2,i+1,j,dp));
            min_cost = min(min_cost,1+solve(word1,word2,i,j+1,dp));
        }
        return dp[i][j]=min_cost;
    }

    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1,vector<int>(word2.size()+1,-1));
        return solve(word1,word2,0,0,dp);
    }
};
