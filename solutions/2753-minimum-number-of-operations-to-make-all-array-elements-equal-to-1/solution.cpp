class Solution {
public:
    int subarray_gcd(vector<int>&nums,int left, int right){
        int prev = nums[left];
        for(int i=left+1;i<=right;i++){
            prev = __gcd(prev,nums[i]);
        }
        return prev;
    }
    int minOperations(vector<int>& nums) {

        int mini = INT_MAX;
        int ones = 0;
        int nonones = 0;
        for(auto& n:nums){
            if(n==1){
                ones++;
            }
            else{
                nonones++;
            }
        }
        if(ones){
            return nonones;
        }
        for(int i =0 ;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                int s = subarray_gcd(nums,i,j);
                if(s==1){
                   mini = min(mini,j-i+1);
                }
            }
        }
        if(mini==INT_MAX)return - 1;
        return nums.size()-1+mini-1;
    }
};
