class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int max_sum = INT_MIN;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum<0){
                sum=0;
            }
            sum+= nums[i];
            max_sum = max(max_sum,sum);
        }
        int max_sum1 = max_sum;
        max_sum=INT_MIN;
        sum=0;
        int total=0;
        for(int i=0;i<nums.size();i++){
            if(sum<0){
                sum=0;
            }
            sum+= -nums[i];
            total+= -nums[i];
            max_sum = max(max_sum,sum);
        }
        int max_sum2 = max_sum;
        if(max_sum2==total){
            return max_sum1;
        }
        return max(max_sum1,max_sum2-total);
    }
};
