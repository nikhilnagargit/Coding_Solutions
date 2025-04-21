class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> PrefixV(nums.size(),1);
        vector<int> SuffixV(nums.size(),1);

        if(nums.size()<2){
            return nums;
        }
        PrefixV[0] = nums[0];
        SuffixV[nums.size()-1]= nums[nums.size()-1];
        for(int i=1;i<nums.size();i++){
            PrefixV[i] = PrefixV[i-1]*nums[i];
        }

        for(int i=nums.size()-2;i>=0;i--){
            SuffixV[i] = SuffixV[i+1]*nums[i];
        }

        nums[0] = SuffixV[1];
        nums[nums.size()-1] = PrefixV[nums.size()-2];

        for(int i=1;i<nums.size()-1;i++){
            nums[i] = PrefixV[i-1]*SuffixV[i+1];
        }
        return nums;
    }
};
