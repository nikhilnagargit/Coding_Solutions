class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> lr(nums.size(),0);
        vector<int> rl(nums.size(),0);
        lr[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            lr[i] = min(lr[i-1],nums[i]);
        }
        rl[nums.size()-1] = nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            rl[i] = max(rl[i+1],nums[i]);
        }

        for(int i=1;i<nums.size();i++){
            if(lr[i]<nums[i] and rl[i]>nums[i]){
                return true;
            }
        }
        return false;
    }
};
