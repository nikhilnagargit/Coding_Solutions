class Solution {
public:

    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()) return false;
        vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1,0));
        dp[0][0]=1;
        for(int i=1;i<=s1.size();i++){
            if(s1[i-1]==s3[i-1] and dp[i-1][0]) dp[i][0]=1;
        }
        for(int i=1;i<=s2.size();i++){
            if(s2[i-1]==s3[i-1] and dp[0][i-1]) dp[0][i]=1;
        }
        for(int i=1;i<=s1.size();i++){
            for(int j=1;j<=s2.size();j++){
                dp[i][j] = 0;
                if(dp[i-1][j]==1 and s3[i+j-1]==s1[i-1]) dp[i][j]=1;
                if(dp[i][j-1]==1 and s3[i+j-1]==s2[j-1]) dp[i][j]=1;
            }
        }
        return dp[s1.size()][s2.size()];
    }
};
