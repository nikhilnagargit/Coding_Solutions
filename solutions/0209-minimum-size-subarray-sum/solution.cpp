class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int right=0;
        int curr_sum = 0;
        int min_size = INT_MAX;

        for(int right=0;right<nums.size();right++){
            curr_sum+= nums[right];
            while(curr_sum>=target and left<=right){
                min_size = min(min_size,right-left+1);
                curr_sum-=nums[left];
                left++;
            }
        }

        if(min_size==INT_MAX) return 0;
        return min_size;
    }
};
