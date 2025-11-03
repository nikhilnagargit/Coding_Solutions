class Solution {
public:

// aabaacab
// *ba??*ab

    bool solve(string& s, string& p, int si, int pi,vector<vector<int>>& dp){
        if(s.size()==si and p.size()==pi){
            return true;
        }
        if(s.size()==si){
                //check if all remaining p are *
                while(pi<p.size()){
                    if(p[pi]!='*'){
                        return false;
                    }
                    pi++;
                }
                return true;
        }
        if(p.size()==pi){
            return false;
        }

        if(dp[si][pi]!=-1){
            return dp[si][pi];
        }

        if(p[pi]=='*'){
            for(int i=si;i<=s.size();i++){
                if(solve(s,p,i,pi+1,dp)){
                    return dp[si][pi]=true;
                }
            }
        }
        else if(p[pi]=='?' or p[pi]==s[si] ){
            if(solve(s,p,si+1,pi+1,dp)){
                return dp[si][pi]=true;
            }
        }
        return dp[si][pi]=false;
    }
    bool isMatch(string s, string p) {
        //preprocessing of *
        string newp ="";
        for(int i=1;i<p.size();i++){
            if(p[i-1]!=p[i] and p[i-1]=='*'){
                newp += '*';
            }
            else if(p[i-1]==p[i] and p[i]=='*'){
                continue;
            }
            else{
                newp+= p[i-1];
            }
        }
        if(p.size()>0)
        newp+= p[p.size()-1];
        // cout<<newp;
        vector<vector<int>> dp(s.size(),vector<int>(newp.size(),-1));
        return solve(s,newp,0,0,dp);
    }
};
