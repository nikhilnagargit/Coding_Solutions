class Solution {
public:
    vector<vector<int>>ans;
     
    void solve(unordered_set<int>& s, vector<int>& v){
        if(s.size()==0){
            ans.push_back(v);
            return;
        }
        unordered_set<int> s_copy = s;
        for(auto item:s){
            v.push_back(item);
            s_copy.erase(item);
            solve(s_copy,v);
            s_copy.insert(item);
            v.pop_back();
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>v;
        unordered_set<int> s(nums.begin(),nums.end());
        solve(s,v);
        return ans;
    }
};
