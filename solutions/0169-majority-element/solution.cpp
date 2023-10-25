class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int majority_item =nums[0];
        int majority_count=1;
        int i=1;
        int j= nums.size()/2;
        while(i<nums.size()){
            if(majority_count>j){
                return majority_item;
            }
            if(nums[i]==majority_item){
                majority_count++;
            }
            else{
                if(majority_count==1){
                    majority_item = nums[i];
                }
                else{
                    majority_count--;
                }
            }
            i++;
        }
        return majority_item;
    }
};
