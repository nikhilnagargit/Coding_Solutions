class Solution {
public:
    int jump(vector<int>& nums) {
        int N= nums.size();
        int dp[N];
        for(int i=0;i<N;i++){
            dp[i] = -1;
        }
        dp[0] = 0;
        int current=0;
        for(int i=0;i<N;i++){
            int j=1;

            while(j<=nums[i] and i+j<N){
               
                if(dp[i+j]==-1){
         
                    dp[i+j] = dp[i]+1;
                }
                if(i+j==N-1){
                    return dp[i+j];
                }
          
                j++;
            }
        }
        return dp[N-1];
        
    }
};
