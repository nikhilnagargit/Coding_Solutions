class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long maxi = 0;
        long long mini = 99999999999;
        for(auto& n:nums){
            if(maxi<n) maxi= n;
            if(mini>n) mini = n;
        }
        long long ans = (maxi-mini)*k;
        return ans;
    }
};
