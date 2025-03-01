class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                nums[i] = nums[i]*2;
                nums[i+1]=0;
            }
        }
        int zeros = 0;
        vector<int>ans;
        for(auto& i:nums){
            if(i==0)zeros++;
            else{
                ans.push_back(i);
            }
        }
        while(zeros--){
            ans.push_back(0);
        }
        return ans;

    }
};
