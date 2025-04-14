class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int prev = nums[0];
        int index=1;
        for(int& num:nums){
            if(num!=prev){
                prev = num;
                nums[index]=num;
                index++;
            }
        }
        return index;

    }
};
