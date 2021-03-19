class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        int index = nums.size()-1;
        vector<int> pums(nums.size(),0);
        for(int k=0;k<nums.size();k++){
            nums[k] = nums[k]*nums[k];
        }
        
        while(j>=i){
            if(nums[i]>=nums[j]){
                pums[index] = nums[i];
                i++;
            }
            else{
                pums[index] = nums[j];
                j--;
            }
            index--;
        }
        return pums;
    }
};
