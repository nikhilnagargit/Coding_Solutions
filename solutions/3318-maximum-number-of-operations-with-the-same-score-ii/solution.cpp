class Solution {
public:
    
     int dp[2001][2001];
    
    int solve(vector<int>& nums,int sum, int left,int right){
        if(left>=right){
            return 0;
        }
         if(dp[left][right]!=-1)return dp[left][right];
        
        int result1 = 0;
        int result2 = 0;
        int result3 = 0;
        
        if(nums[left]+nums[left+1]==sum)
            result1 = 1+solve(nums,sum,left+2,right);
        if(nums[right]+nums[right-1]==sum)
            result2 = 1+solve(nums,sum,left,right-2);
        if(nums[left]+nums[right]==sum)
            result3 = 1+solve(nums,sum,left+1,right-1);
        
        return dp[left][right]=max(result1,max(result2,result3));
        
    }
    
    int maxOperations(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
  
        int sum1= nums[0]+nums[1];
        int sum2 = nums[nums.size()-1]+nums[nums.size()-2];
        int sum3 = nums[0]+nums[nums.size()-1];
        
        int result1 = 1+solve(nums,sum1,2,nums.size()-1);
        int result2 = 1+solve(nums,sum2,0,nums.size()-3);
        int result3 = 1+solve(nums,sum3,1,nums.size()-2);
        
        return max(result1,max(result2,result3));
    }
};
