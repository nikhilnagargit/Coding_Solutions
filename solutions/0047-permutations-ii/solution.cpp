class Solution {
public:
    void solve(vector<int> nums,vector<vector<int>>&ans, vector<int>& v){
        if(nums.size()==0){
            ans.push_back(v);
            return;
        }
        vector<int> nums_copy = nums;
        for(int i=0;i<nums.size();i++){
            if(i>0 and nums[i-1]==nums[i]){
                continue;
            }
            int t= nums[i];
            v.push_back(nums[i]);
            nums.erase(nums.begin()+i);
            solve(nums,ans,v);
            nums.insert(nums.begin()+i,t);
            v.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> v;
        solve(nums,ans,v);
        return ans;
    }
};
