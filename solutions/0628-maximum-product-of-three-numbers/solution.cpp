class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxP = INT_MIN;
        for(int i=1;i<nums.size()-1;i++){
            int a = nums[i];
            int b = nums[i-1];
            int c = nums[nums.size()-1];
            maxP = max(maxP,a*b*c);
        }
        return maxP;
    }
};
