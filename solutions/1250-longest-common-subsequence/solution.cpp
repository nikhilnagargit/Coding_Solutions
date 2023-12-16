class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(),vector<int>(text2.size(),0));
        if(text1[0]==text2[0]) dp[0][0] = 1;
                    else dp[0][0] = 0;

        for(int i=0;i<text1.size();i++){
            for(int j=0;j<text2.size();j++){
                if(i==0 and j==0){

                }
                else if(i==0){
                    if(text1[i]==text2[j]){
                        dp[i][j] = 1;
                    }
                    else {
                        dp[i][j] = dp[i][j-1];
                    }
                }
                else if(j==0){
                    if(text1[i]==text2[j]){
                        dp[i][j] = 1;
                    }
                    else {
                        dp[i][j] = dp[i-1][j];
                    }                    
                }
                else{
                    if(text1[i]==text2[j]){
                        dp[i][j] = max(dp[i][j-1],dp[i-1][j-1]+1);
                    }
                    else {
                        dp[i][j] = max(dp[i][j-1],dp[i-1][j-1]);
                    }
                    dp[i][j] = max(dp[i][j],dp[i-1][j]);
                }
            }
        }
        return dp[text1.size()-1][text2.size()-1];
    }
};
