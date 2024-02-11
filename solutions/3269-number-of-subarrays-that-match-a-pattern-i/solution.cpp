class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int count = 0;
        for(int i =0 ;i<nums.size()-pattern.size();i++){
            int flag = 1;
            for(int k=0;k<pattern.size();k++){
                if(pattern[k]==0 and nums[i+k+1]==nums[i+k]){
                }
                else if(pattern[k]==1 and nums[i+k+1]>nums[i+k]){
                    
                }
                else if(pattern[k]==-1 and nums[i+k+1]<nums[i+k]){
                    
                }
                else{
                    flag = 0;
                    break;
                }
            }
            if(flag) count++;
        }
        return count;
    }
};
