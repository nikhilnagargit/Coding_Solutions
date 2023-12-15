class Solution {
public:
    vector<vector<int>> ans;
    void solve(int k,int n, int i,vector<int>& v){
        if(k==v.size() and n==0){
            ans.push_back(v);
            return;
        }
        if(i>9 or n<=0 or v.size()>=k){
            return;
        }
        solve(k,n,i+1,v);
        v.push_back(i);
        solve(k,n-i,i+1,v);
        v.pop_back();
    }
    vector<vector<int>> combinationSum3(int k, int n) {        
        vector<int>v;
        solve(k,n,1,v);
        return ans;
    }
};
