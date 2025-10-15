class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int prev = INT_MAX;
        int curr =1 ;
        int ans = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=nums[i-1]){
                ans  = max(ans,curr/2);
                if(prev!=INT_MAX)
                ans = max(ans,min(prev,curr));
                prev = curr;
                curr = 0;
            }
            curr++;
        }
            ans  = max(ans,curr/2);
              if(prev!=INT_MAX)
            ans = max(ans,min(prev,curr));
        return ans;
    }
};
