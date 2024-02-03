class Solution {
public:
    int solve(vector<int>& arr, int k , int i,vector<int>& dp){
        if(i>=arr.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int n = arr.size();
        int N = min(k+i,n);
        vector<int> sumarr (k,0);
        int currmax = arr[i];
        for(int j = i;j<N;j++){
            currmax = max(currmax,arr[j]);
            sumarr[j-i] = currmax*(j-i+1) + solve(arr,k,j+1,dp); 
        }
        int maxi = 0;
        for(auto i:sumarr){
            maxi = max(maxi,i);
        }
        return dp[i]=maxi;
        
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>dp(arr.size()+1,-1);
        return solve(arr,k,0,dp);
    }
};
