class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums,int i,vector<int>& v){
        ans.push_back(v);
        for(int j=i;j<nums.size();j++){
            if(j>i and nums[j]==nums[j-1]) continue;
            v.push_back(nums[j]);
            solve(nums,j+1,v);
            v.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> v;
        sort(nums.begin(),nums.end());
        solve(nums,0,v);
        return ans;
    }
};
