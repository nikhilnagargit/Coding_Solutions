class Solution {
public:
    void solve(vector<int>& candidates,int target,vector<vector<int>>& ans,vector<int>&v,int idx){
        if(target==0){
            ans.push_back(v);
            return;
        }
        if(target<0 or idx>=candidates.size()){
            return;
        }
        for(int i=idx;i<candidates.size();i++){
            v.push_back(candidates[i]);
            solve(candidates,target-candidates[i],ans,v,i);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        solve(candidates,target,ans,v,0);
        return ans;
    }
};
