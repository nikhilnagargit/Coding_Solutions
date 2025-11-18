class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int element = -1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==element){
                count++;
            }
            else{
                if(count==1){
                    element = nums[i];
                }
                else{
                    count--;
                }
            }
        }
        return element;
    }
};
