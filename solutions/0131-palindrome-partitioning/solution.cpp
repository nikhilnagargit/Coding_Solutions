class Solution {
public:
    
    void solve(string&s , int i, vector<string>& v, vector<vector<int>>& dp,vector<vector<string>>& ans){
        if(i==s.size()){
            ans.push_back(v);
            return;
        }
        //partition at each index since i, 
        for(int k=i;k<s.size();k++){
            //if current parts is paindrome, move to next one
            string curr = s.substr(i,k-i+1);
            if(dp[i][k]){
                v.push_back(curr);
                solve(s,k+1,v,dp,ans);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
         vector<vector<string>>ans;
        vector<string> v;
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),0));
        for(int diag=0;diag<s.size();diag++){
            for(int i=0;i<(s.size()-diag);i++){
                if(diag==0){
                    dp[i][diag+i] = 1;
                }
                else if(diag==1){
                    dp[i][diag+i] = (s[i]==s[diag+i]);
                }
                else{
                    dp[i][diag+i] = (s[i]==s[diag+i]) and (dp[i+1][diag+i-1]);
                }
            }
        }
        solve(s,0,v,dp,ans);
        return ans;
    }
};
