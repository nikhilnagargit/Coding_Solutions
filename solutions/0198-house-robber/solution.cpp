class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,0);
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);
        int prevprevHouse=nums[0];
        int prevHouse=max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++){
            int temp = max(prevprevHouse+nums[i],prevHouse);
            prevprevHouse = prevHouse;
            prevHouse = temp;
        }
        return (prevHouse);
    }
};
