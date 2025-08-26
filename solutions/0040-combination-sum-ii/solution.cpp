class Solution {
public:
    vector<vector<int>>ans;

    void solve(vector<int>&candidates,int start,int target,vector<int>& v){
        if(target==0){
            ans.push_back(v);
            return;
        }
        if(target<0) return;
        for(int i=start;i<candidates.size();i++){
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            if(candidates[i]>target) break;
            v.push_back(candidates[i]);
            solve(candidates,i+1,target-candidates[i],v);
            v.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> v;
        solve(candidates,0,target,v);
        return ans;
    }
};
