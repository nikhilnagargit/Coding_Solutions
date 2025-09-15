class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        if(nums.size()<=3) return ans;
        for(int i=0;i<nums.size()-3;i++){
            if(i>0 and nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<nums.size()-2;j++){
                if(j>i+1 and nums[j]==nums[j-1]){continue;}
                long long rem_sum = 1ll*target-(1ll*nums[i]+1ll*nums[j]);
                int left = j+1;
                int right = nums.size()-1;
                while(left<right){
                    int sum = nums[left]+nums[right];
                    if(sum==rem_sum){
                        ans.push_back({nums[i],nums[j],nums[left],nums[right]});
                        while(left+1<right and nums[left]==nums[left+1]){
                            left++;
                        }
                        while(left+1<right and nums[right-1]==nums[right]){
                            right--;
                        }
                        left++;
                        right--;
                    }
                    else if(sum>rem_sum){
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
