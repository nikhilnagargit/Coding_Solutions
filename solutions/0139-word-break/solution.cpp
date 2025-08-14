class Solution {
public:


    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size()+1,0);
        dp[0] = 1;
        for(int i=1;i<=s.size();i++){
            for(auto w:wordDict){
                int start = i-w.size();
                if(start>=0 and dp[start] and s.substr(start,w.size())==w){
                    dp[i]=1;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};
