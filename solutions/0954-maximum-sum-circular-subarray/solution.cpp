class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        // use kadanes
        int maxSum = nums[0];
        int currSum = 0;
        int total =0 ;

        for(int i=0;i<nums.size();i++){
            currSum+= nums[i];
            maxSum = max(maxSum,currSum);
            if(currSum<0){
                currSum=0;
            }
            total+= nums[i];
        }


        // second kadane
        currSum =0 ;
        int maxNegSum = -nums[0];
        for(int i=0;i<nums.size();i++){
            currSum+= -nums[i];
            maxNegSum = max(maxNegSum,currSum);
            if(currSum<0){
                currSum=0;
            }
        }   
        if(maxNegSum+total==0) return maxSum;
        return max(maxSum, total+maxNegSum);

        // return maxSum;

    }
};
