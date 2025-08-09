class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int largestSum = INT_MIN;
        int sumTillNow = 0;
        for(int i=0;i<nums.size();i++){
            if(sumTillNow<0){
                sumTillNow=0;
            }
            sumTillNow+= nums[i];
            largestSum = max(largestSum,sumTillNow);
        }
        return largestSum;
    }
};
