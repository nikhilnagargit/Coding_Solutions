class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        //sliding window
        int left = 0;
        int maxlength = 0;
        int zeros = 0;
        for(int right=0;right<nums.size();right++){
            if(nums[right]!=1){
                zeros+=1;
            }
            if(zeros>1){
                while(nums[left]!=0){
                    left++;
                }
                left++;
                zeros -= 1;
            }
            maxlength = max(maxlength,right-left);
        }
        return maxlength;
    }
};
