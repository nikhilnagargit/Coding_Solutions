class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = LONG_MIN, preSum = 0;
        unordered_map<int, vector<int>> mp;
        vector<long long> pre;
        for(auto it : nums){
            preSum += it;
            pre.push_back(preSum);
        }
        mp[nums[0]].push_back(0);
        for(int i = 1 ; i < n; i++){
            int diff1 = nums[i] - k, diff2 = nums[i] + k;
            if(mp.contains(diff1)){
                auto& vec = mp[diff1];
                for(auto it : vec)
                    ans = max(ans, (pre[i] - pre[it]) + nums[it]);
            }
            if(mp.contains(diff2)){
                auto& vec = mp[diff2];
                for(auto it : vec)
                    ans = max(ans, (pre[i] - pre[it]) + nums[it]);
            }
            mp[nums[i]].push_back(i);
        }
        return ans != LONG_MIN ? ans : 0;
    }
};
