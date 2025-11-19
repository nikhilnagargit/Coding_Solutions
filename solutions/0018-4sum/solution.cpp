class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.size()<4){
            return {};
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-3;i++){
            if(i>0 and nums[i-1]==nums[i]) continue;
            for(int j=i+1;j<nums.size()-2;j++){
                if(j>i+1 and nums[j-1]==nums[j]) continue;
                int left = j+1;
                int right = nums.size()-1;
                while(left<right){
                    if((1ll*nums[left]+1ll*nums[right]+1ll*nums[i]+1ll*nums[j])==target){
                        ans.push_back({nums[i],nums[j],nums[left],nums[right]});
                        while(left<right and nums[left]==nums[left+1])
                        left++;
                        while(left<right and nums[right]==nums[right-1])
                        right--;
                        left++;
                        right--;
                    }
                    else if(1ll*nums[left]+1ll*nums[right]+1ll*nums[i]+1ll*nums[j]>target){
                        right--;
                    }
                    else{
                        left++;
                    }
                }
            }
        }
        return ans;
    }
};
