class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),0));
        string maxi = "";
        for(int diag=0;diag<s.size();diag++){
            int starti = 0;
            int startj = diag;
            for(int step=0;step<s.size()-diag;step++){
                int  i = starti+step;
                int  j = startj+step;
                if(i==j){
                    dp[i][j]=1;
                }
                else if(i==j-1 and s[i]==s[j]){
                    dp[i][j] =1 ;
                }
                else if(s[i]==s[j]){
                    dp[i][j]=dp[i+1][j-1];
                }
                else{
                    dp[i][j]=0;
                }

                if(dp[i][j]==1 and maxi.size()<j-i+1){
                    maxi = s.substr(i,j-i+1);
                }
            }
        }
        return maxi;
    }
};
