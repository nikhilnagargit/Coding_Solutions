class Solution {
public:
    bool increasing(vector<int>& nums,int s,int k){
        for(int i=s+1;i<s+k;i++){
            if(nums[i]<=nums[i-1]){
                return false;
            }
        }
        return true;
    }
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int a = 0;
        int b = k;
        for(int i=0;i<=nums.size()-2*k;i++){
            int a = i;
            int b = i+k;
            //check first inv
            if(increasing(nums,a,k) and increasing(nums,a+k,k)){
                return true;
            }
        }
        return false;
    }
};
