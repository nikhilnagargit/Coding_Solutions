class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>&candidates,int& target,int& sum,vector<int>&v,int start){
        if(sum>target) return;
        if(sum==target){
            ans.push_back(v);
            return;
        }
        for(int i=start;i<candidates.size();i++){
            sum+= candidates[i];
            v.push_back(candidates[i]);
            solve(candidates,target,sum,v,i);
            v.pop_back();
            sum-= candidates[i];
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int sum = 0;
        vector<int>v;
        solve(candidates,target,sum,v,0);
        return ans;
    }
};
