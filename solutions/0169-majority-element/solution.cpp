class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int curr = nums[0];
        int count = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=curr and count==0){
                curr =nums[i];
                count = 1;
            }
            else if(nums[i]!=curr and count>0){
                count--;
            }
            else if(nums[i]==curr){
                count++;
            }
        }
        return curr;
    }
};
