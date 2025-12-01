class Solution {
public:
    void solve(vector<int>& v, vector<vector<int>>& ans,unordered_set<int> s){
        if(s.size()==0){
            ans.push_back(v);
            return;
        }

        for(auto item:s){
            v.push_back(item);
            unordered_set<int>s_copy = s;
            s_copy.erase(item);
            solve(v,ans,s_copy);
            v.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        unordered_set<int> s(nums.begin(),nums.end());
        solve(v,ans,s);
        return ans;
    }
};
