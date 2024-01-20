class Solution {
public:

    bool canSortArray(vector<int>& nums) {
    

        for(int i=1;i<nums.size();i++){
            for(int j=i-1;j>=0;j--){
                if(__builtin_popcount(nums[j])!=__builtin_popcount(nums[i]) and nums[i]<nums[j]){
                    return false;
                }
            }
        }
        return true;
    }
};
