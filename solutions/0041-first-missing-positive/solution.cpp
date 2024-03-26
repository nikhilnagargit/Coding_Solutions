class Solution {
public:

    int firstMissingPositive(vector<int>& nums) {
        // check if 1 is there
        bool isOne = false;
        for(auto i:nums){
            if(i==1) {isOne=true;break;}
        }
        if(!isOne) return 1;
        // make all negative and 0s and out of range nums to 1
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=0 or nums[i]>nums.size()){
                nums[i] = 1;
            }
        }
  
        // start marking index exists or not as nums[i] value
        for(int i=0;i<nums.size();i++){
             nums[abs(nums[i])-1] = abs(nums[abs(nums[i])-1])*-1;
        }
 
        // find first positive value
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0) return i+1; 
        }
        return nums.size()+1;
    }
};
