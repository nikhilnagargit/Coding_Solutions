class Solution {
public:
    int solve(vector<pair<int,int>>& v, int idx, int m, int n,vector<vector<vector<int>>>&dp){
        if( m<0 or n<0) return -1;
        if(idx>=v.size()) return 0;
        if(dp[idx][m][n]!=-1) return dp[idx][m][n];

        //take it
        int a = solve(v,idx+1,m-v[idx].first,n-v[idx].second,dp);
        if(a!=-1) a++;
        //not take it
        int b = solve(v,idx+1,m,n,dp);
        return dp[idx][m][n]=max(a,b);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>> v;
        for(auto& s: strs){
            int zeros = 0;
            int ones = 0;
            for(auto& c:s){
                if(c=='0') zeros++; else ones++;
            }
            v.push_back({zeros,ones});
        }
        vector<vector<vector<int>>> dp (601,vector<vector<int>>(101,vector<int>(101,-1)));
        return solve(v,0,m,n,dp);
    }
};
