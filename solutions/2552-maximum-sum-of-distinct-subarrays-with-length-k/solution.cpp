class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long max_sum = 0;
        long long curr_sum = 0;
        unordered_map<int,int> mp;
        for(int i=0;i<k;i++){
            mp[nums[i]]++;
            curr_sum += nums[i];
        }

        if(mp.size()==k){
            max_sum = curr_sum;
        }

        for(int i=k;i<nums.size();i++){
            // remove i-k index element from map
            mp[nums[i-k]]--;
            if(mp[nums[i-k]]==0){
                mp.erase(nums[i-k]);
            }
            curr_sum -= nums[i-k];

            // add i index element to map
            mp[nums[i]]++;
            curr_sum += nums[i];

            //check if all are unique
            if(mp.size()==k){
                max_sum = max(max_sum,curr_sum);
            }
        }


        return max_sum;

    }
};
