class Solution {
public:

    int solve(int current_index,int remaining_steps,int arrLen,vector<vector<int>>& dp){
        if(remaining_steps==0 and current_index==0){
            return 1;
        }
        if(current_index<0 or current_index>arrLen-1){
            return 0;
        }
        if(remaining_steps==0 and current_index!=0){
            return 0;
        }
        if(dp[current_index][remaining_steps]!=-1){
            return dp[current_index][remaining_steps];
        }
        int a = solve(current_index,remaining_steps-1,arrLen,dp)%(1000000007);
        int b = solve(current_index+1,remaining_steps-1,arrLen,dp)%(1000000007);
        int c = solve(current_index-1,remaining_steps-1,arrLen,dp)%(1000000007);

        dp[current_index][remaining_steps] = (a+b)%(1000000007);
        dp[current_index][remaining_steps] = (dp[current_index][remaining_steps] + c)%(1000000007);
        return dp[current_index][remaining_steps];
    }

    int numWays(int steps, int arrLen) {
        vector<vector<int>> dp( 501 , vector<int> (501, -1));
        return solve(0,steps,arrLen,dp);
    }
};
