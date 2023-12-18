class Solution {
public:
    vector<vector<int>> dp;
    int solve(string& word1,string& word2,int i,int j){
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(j==word2.size()){
            return (word1.size()-i);
        }
        if(i==word1.size()){
            return (word2.size()-j);
        }
        if(word1[i]==word2[j]){
            return  dp[i][j]= solve(word1,word2,i+1,j+1);
        }
        int result ;
        result = min(solve(word1,word2,i+1,j),solve(word1,word2,i+1,j+1));
        result = min(result,solve(word1,word2,i,j+1));        
        return dp[i][j]=1+result;
    }

    int minDistance(string word1, string word2) {
        if(word1.size()<word2.size()){
            minDistance(word2,word1);
        }
        dp = vector<vector<int>>(501,vector<int>(501,-1));
        return solve(word1,word2,0,0);
    }
};
