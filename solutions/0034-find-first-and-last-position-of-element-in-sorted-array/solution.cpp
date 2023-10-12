class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
         vector<int>ans;
        bool is_there = binary_search(nums.begin(),nums.end(),target);
        if(is_there){
        int start = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        int end = upper_bound(nums.begin(),nums.end(),target)- nums.begin() - 1;
       
        ans.push_back(start);
        ans.push_back(end);
        return ans;
        }
        ans.push_back(-1);
                ans.push_back(-1);

        return ans;
        
    }
};
