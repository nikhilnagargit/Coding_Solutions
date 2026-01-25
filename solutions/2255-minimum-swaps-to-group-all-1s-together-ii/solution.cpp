class Solution {
public:
    int minSwaps(vector<int>& nums) {
        // find the min zero in sliding window of circular suffix added array
        int x = 0;
    
        for(auto& item: nums){
            if(item==1) x++;
        }
        int zeros= 0;
        for(int i=0;i<x;i++){
            if(nums[i]==0)zeros++;
        }
        int minZeros = zeros;
        for(int i=x;i<nums.size();i++){
            if(nums[i]==0){
                zeros++;
            }
            if(nums[i-x]==0){
                zeros--;
            }
            minZeros = min(minZeros,zeros);
        }
        int n = nums.size();


        // try with other window
        zeros = 0;
        
        for(int i=0;i<n-x;i++){
            if(nums[i]==0)zeros++;
        }
        int maxZeros = zeros;

        for(int i=n-x;i<nums.size();i++){
            if(nums[i]==0){
                zeros++;
            }
            if(nums[i-(n-x)]==0){
                zeros--;
            }
            maxZeros = max(maxZeros,zeros);
        }
        return min(minZeros, (n-x)-maxZeros);
    }
};
