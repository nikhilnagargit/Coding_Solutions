class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        long long ans = 0;
        for(int i=0;i<nums.size();i++){
            long long num = nums[i];
            long long max_num = upper - num;
            long long min_num = lower - num;
            auto right_limit = upper_bound(nums.begin()+i+1,nums.end(),max_num)-nums.begin();
            auto left_limit = lower_bound(nums.begin()+i+1,nums.end(),min_num)-nums.begin();
            // cout<<"right_limit:"<<right_limit<<",left limit:"<<left_limit<<endl;
            ans += abs(right_limit - left_limit);
        }
        return ans;
    }
};
