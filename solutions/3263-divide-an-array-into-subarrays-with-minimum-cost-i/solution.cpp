class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int ans = INT_MAX;
         int i=0;
            for(int j=i+1;j<nums.size();j++){
                for(int k= j+1;k<nums.size();k++){
                    ans = min(ans,nums[i]+nums[j]+nums[k]);
                }
            
        }
        return ans;
    }
};
