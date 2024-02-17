class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int sum = nums[0]+nums[1];
        int i=2;
        int count = 1;
        while(i+1<nums.size()){
            if(nums[i]+nums[i+1]!=sum)return count; 
            i++;
            i++;
            count++;
        }
        return count;
    }
};
