class Solution {
public:
    void generate_subsets_of_size_n(int i,vector<int>&nums,vector<vector<int>>& ans,vector<int>& subset){
        if(nums.size()==i){
            ans.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        generate_subsets_of_size_n(i+1,nums,ans,subset);
        subset.pop_back();
        generate_subsets_of_size_n(i+1,nums,ans,subset);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
            vector<int> subset;
            generate_subsets_of_size_n(0,nums,ans,subset);
        return ans;
    }
};
