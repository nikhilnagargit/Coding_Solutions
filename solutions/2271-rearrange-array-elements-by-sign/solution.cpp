class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>ans(nums.size());
        int even = 0;
        int odd = 1;
        int i = 0;
        while(i<nums.size()){
            if(nums[i]<0){
                ans[odd]= nums[i];
                odd+=2;
            }
            else if(nums[i]>=0){
                ans[even] = nums[i];
                even++;
                even++;
            }
            i++;
        }
        return ans;
    }
};
