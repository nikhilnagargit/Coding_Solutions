class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int maxi = 1;
        int left = 0;
        int right = 1;
        long long windowSum = nums[0];
        while(right<nums.size()){
            // include next right index in sum
            long long  a = nums[right];
            long long temp = a*(right-left);
            if(temp - windowSum <= k){
                windowSum = windowSum+nums[right];
                right++;
            }
            else{
                windowSum -= nums[left];
                left++;
            }
            maxi = max(maxi,right-left);
        }
        return maxi;
    }
};
