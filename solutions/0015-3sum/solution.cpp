class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<nums.size()-2;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int left = i+1;
            int right = nums.size()-1;
            while(left<right){
                if(nums[left]+nums[right]+nums[i]==0){
                    ans.push_back({nums[i],nums[left],nums[right]});
                    left++;
                    while(nums[left]==nums[left-1] && left<right){
                        left++;
                    }
                    right--;
                    while(nums[right]==nums[right+1]&& left<right){
                        right--;
                    }
                }
                else if(nums[left]+nums[right]+nums[i]>0){
                    right--;
                }
                else{
                    left++;
                }
            }
        }
        return ans;

    }
};
