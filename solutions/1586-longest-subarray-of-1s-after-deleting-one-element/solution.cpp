class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left  =0 ;
        int right =0;
        int maxi = 0;
        bool isdeleted = false;
        while(right<nums.size()){
            if(nums[right]==1){
                right++;
            }
            else if(nums[right]==0 and isdeleted==false){
                right++;
                isdeleted = true;
            }
            else {
                while(nums[left]!=0){
                    left++;
                }
                left++;
                right++;
            }
            maxi = max(maxi,right-left-1);
        }
        return maxi;
    }
};
