class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int max_outlier = INT_MIN;
        int total_sum = accumulate(nums.begin(),nums.end(),0);
        unordered_map<int,int> m;
        for(auto n:nums){
            m[n]++;
        }
        
        for(int i=0;i<nums.size();i++){
            int remaining_sum = total_sum - nums[i];
            m[nums[i]]--;
            if(remaining_sum%2!=0){
                m[nums[i]]++;
                continue;
            }
            if(m[remaining_sum/2]>0){
                max_outlier = max(max_outlier,nums[i]);
            }
            m[nums[i]]++;
        }
        return max_outlier;
    }
};
