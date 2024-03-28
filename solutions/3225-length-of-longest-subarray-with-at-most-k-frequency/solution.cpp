class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int maxWindowSize = 1;
        int right = 0;
        int left = 0;
        unordered_map<int,int> freq;
        while(right<nums.size()){
            // expand the window 
            while(right<nums.size() and freq[nums[right]]+1<=k){
                freq[nums[right]]++;
                right++;
            }
            // check the size of window
            maxWindowSize = max(maxWindowSize,right-left);
            // reduce the size of window
            while(right<nums.size() and left<right and freq[nums[right]]+1>k){
                freq[nums[left]]--;
                left++;
            }
        } 
        return maxWindowSize;
    }
};
