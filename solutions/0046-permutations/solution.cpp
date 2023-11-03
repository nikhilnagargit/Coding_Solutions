class Solution {
public:
    void permuteRec(vector<int>& nums, int begin, vector<vector<int>>& result) {
        if (begin == nums.size()) {
            result.push_back(nums);
            return;
        }
        for (int i = begin; i < nums.size(); i++) {
            // Swap
            int temp = nums[begin];
            nums[begin] = nums[i];
            nums[i] = temp;
            
            permuteRec(nums, begin + 1, result);
            
            // Swap back
            temp = nums[begin];
            nums[begin] = nums[i];
            nums[i] = temp;
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        permuteRec(nums, 0, result);
        return result;
    }
};
