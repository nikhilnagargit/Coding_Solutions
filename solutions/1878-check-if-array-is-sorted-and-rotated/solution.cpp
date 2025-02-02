class Solution {
public:
    bool check(vector<int>& nums) {
        int breakcount = 0;
        if(nums.size()<=1)return true;

        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i]){
                breakcount++;
            }
        }
        if(nums[0]<nums[nums.size()-1]){
            breakcount++;
        }
        if(breakcount>1){
            return false;
        }
        return true;
    }
};
