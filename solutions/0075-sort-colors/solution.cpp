class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                swap(nums[left],nums[i]);
                left++;
            }
        }
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]==2){
                swap(nums[right],nums[i]);
                right--;
            }
        }
    }
};
