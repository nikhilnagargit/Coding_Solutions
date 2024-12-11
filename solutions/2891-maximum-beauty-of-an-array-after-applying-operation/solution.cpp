class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        // 1,2,4,6
        sort(nums.begin(),nums.end());
        int K = 2*k;
        int ans = 0;
        int left = 0;
        int right = 0;
        while(right<nums.size()){
            if(nums[right]-nums[left]>K){
                left++;
            }
            else{
                right++;
                ans = max(ans,right-left);
            }
            
        }
        return ans;
    }
};
