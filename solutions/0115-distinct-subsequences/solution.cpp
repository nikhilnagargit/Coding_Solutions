class Solution {
public:
    int numDistinct(string s, string t) {
       vector<double> dp(t.size()+1,0);
       dp[0]=1;
        for(int i=1;i<=s.size();i++){
            vector<double> temp = dp;
            for(int j=1;j<=t.size();j++){
                    if(s[i-1]==t[j-1]){
                        temp[j] = dp[j-1]+dp[j];
                    }
                    else{
                        temp[j] = dp[j];
                    }
            }
            dp = temp;
        }
        return dp[t.size()];
    }
};
