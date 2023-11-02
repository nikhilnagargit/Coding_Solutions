class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string> myset(wordDict.begin(),wordDict.end());

        vector<bool> dp(s.size()+1,false);
        dp[0]=true;

        for(int i=1;i<=s.size();i++){
 
            for(int j=i;j>=0;j--){
                if(dp[j]){
          
                    string temp = s.substr(j,i-j);
          
                    if(myset.find(temp)!=myset.end()){
                        dp[i] = true;
         
                        break;
                    }
                }
            }
        }


        return dp[s.size()];
    }
};
