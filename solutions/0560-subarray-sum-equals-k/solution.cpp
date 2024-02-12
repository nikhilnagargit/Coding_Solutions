class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int>sum(nums.size(),0);
        sum[0] = nums[0];
        int ans = 0;
        for(int i=1;i<nums.size();i++){
            sum[i]=sum[i-1]+nums[i];
        }
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
            
                if(i>=1 and sum[j]-sum[i-1]==k) ans++;
                else if(i==0 and sum[j]==k){
                    ans++;
                }
            }
        }
        return ans;
    }
};
