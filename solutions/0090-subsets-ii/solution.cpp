class Solution {
public:
    void solve(vector<int>& v, int i,vector<vector<int>>& ans,vector<int>& nums){
        ans.push_back(v);
        for(int k=i;k<nums.size();k++){
            if(k==i or nums[k]!=nums[k-1]){
            v.push_back(nums[k]);
            solve(v,k+1,ans,nums);
            v.pop_back();
            }
        }
        return;

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> v;
        solve(v,0,ans,nums);
        return ans;
    }
};
