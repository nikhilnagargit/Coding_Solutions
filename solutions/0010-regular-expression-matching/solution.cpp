class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(p.size()+1, vector<bool>(s.size()+1,false));
        
        for(int i=0;i<=p.size();i++){
            for(int j=0;j<=s.size();j++){
                if(i==0 && j==0){
                    dp[i][j]=true;
                }
                else if(i==0){
                    dp[i][j]=false;
                }
                else if(j==0){
                    if(p[i-1]=='*'){
                        dp[i][j] = dp[i-2][j];   // zero of preceding char
                    }
                    else{
                        dp[i][j] = false;
                    }
                }
                else{
                    if(p[i-1]=='*'){
                        // check without using this "x*"
                        bool ans = dp[i-2][j];
                        // check with using it (stay on i, move string back)
                        if(p[i-2]=='.'){
                            ans = ans || dp[i][j-1];
                        }
                        else{
                            ans = ans || (dp[i][j-1] && (p[i-2]==s[j-1]));
                        }
                        dp[i][j]=ans;
                    }
                    else{
                        if(p[i-1]=='.'){
                            dp[i][j]=dp[i-1][j-1];
                        }
                        else{
                            dp[i][j] = dp[i-1][j-1] && (p[i-1]==s[j-1]);
                        }
                    }
                }
            }
        }
        return dp[p.size()][s.size()];
    }
};

