class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeros = 0;
        int left =  0;
        int right = 0;
        int windowsize = 0;
        int maxi = 0;
        while(right<nums.size()){
            if(nums[right]==1){
                right++;
            }
            else if(nums[right]==0 and zeros<k){
                zeros++;
                right++;
            }
            else if(nums[right]==0 and zeros>=k){
                while(nums[left]!=0){
                    left++;
                }
                left++;
                right++;
            }
            maxi = max(maxi,right-left);
        }
        return maxi;
    }
};
