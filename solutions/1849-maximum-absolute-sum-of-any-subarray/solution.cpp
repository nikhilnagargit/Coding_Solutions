class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int i=1;
        int maxSumPositive = nums[0]>0?nums[0]:0;
        int currSum = nums[0]>0?nums[0]:0;;
        while(i<nums.size()){
            if(nums[i]+currSum>0){
                currSum+=nums[i];
                i++;
            }
            else{
                i++;
                currSum = 0;
            }
            maxSumPositive = max(maxSumPositive,currSum);
        }
 
        // for(int i=0;i<nums.size();i++){
        //     nums[i] = -1*nums[i];
        // }
        i=1;
        int maxSumNegative = nums[0]<0?nums[0]:0;
        currSum = nums[0]<0?nums[0]:0;
        while(i<nums.size()){
            if(nums[i]+currSum<0){
                currSum+=nums[i];
                i++;
            }
            else{
                i++;
                currSum = 0;
            }
            maxSumNegative = min(currSum,maxSumNegative);
        }
        return max(maxSumPositive,abs(maxSumNegative));
    }
};
