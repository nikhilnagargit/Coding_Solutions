class Solution {
public:
    unordered_map<string,int>dp;
    int solve(vector<int>&nums,int curr,int target,int sum){
        
        if(curr==nums.size()){
            if((sum)==target){
                return 1;
            }
            return 0;
        }
        string s = to_string(curr)+"-"+to_string(sum);
        if(dp.count(s)){
            return dp[s];
        }
        return dp[s]= solve(nums,curr+1,target,sum+nums[curr]) + solve(nums,curr+1,target,sum-nums[curr]);

    }
    int findTargetSumWays(vector<int>& nums, int target) {

        return solve(nums,0,target,0);

    }
};
