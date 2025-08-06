class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(int& n,int i,int& k,vector<int>& v){
        if(v.size()==k){
            ans.push_back(v);
            return;
        }
        if(i>n){
            return;
        }
        solve(n,i+1,k,v);
        
        v.push_back(i);
        solve(n,i+1,k,v);
        v.pop_back();
 
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> v;
        int i=1;
        solve(n,i,k,v);
        return ans;
    }
};
