class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int nearestsum = nums[0]+nums[1]+nums[2];
        for(int i=0;i<nums.size()-2;i++){
            int left = i+1;
            int right = nums.size()-1;
            //go from left to right
            while(left<right){
                int sum = nums[left]+nums[right]+nums[i];
                if(abs(sum-target)<abs(nearestsum-target)){
                    nearestsum = sum;
                }
                if(sum>target){
                    right--;
                }
                else if(sum<target){
                    left++;
                }
                else{
                    return sum;
                }
            }
        }
        return nearestsum;
    }
};
