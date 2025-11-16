class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0];
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]>0){
                sum = sum+nums[i];
                max_sum = max(max_sum,sum);
            }
            else{
                max_sum = max(max_sum,nums[i]);
                sum = 0;
            }
        }
        return max_sum;
    }
};
