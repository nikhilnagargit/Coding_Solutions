class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = *max_element(nums.begin(),nums.end());
        int count = 0;
        int maxCount = 0;
        for(auto& n:nums) {
            if(n==maxi){
                count++;
                maxCount =max(maxCount,count);
            }
            else{
                count=0;
                }
        }
        return maxCount;
    }
};
