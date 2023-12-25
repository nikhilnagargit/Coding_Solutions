class Solution {
public:
    int solve(string& s,int idx,vector<int>& dp){
        if(idx==s.size()){
            return 1;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        if(s[idx]=='0'){
            return 0;
        }
        int singleDigitDecodeWays = solve(s,idx+1,dp);
        int doubleDigitDecodeWays = 0;
        if(idx<s.size()-1){
            int first =  s[idx]-'0';
            int second = s[idx+1]-'0';
            int num = first*10+second;
            if(first==0){

            }
            else if(num<=26){
                doubleDigitDecodeWays = solve(s,idx+2,dp);
            }
        }
        return dp[idx]= singleDigitDecodeWays+doubleDigitDecodeWays;
    }
    int numDecodings(string s) {
        vector<int>dp(s.size()+1,-1);
        return solve(s,0,dp);
    }
};
