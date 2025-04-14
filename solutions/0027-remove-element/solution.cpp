class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0;
        int curr=0;
        int count = 0;
        while(curr<nums.size()){
            if(nums[curr]==val){
                curr++;
            }
            else{
                nums[i]=nums[curr];
                i++;
                curr++;
                count++;
            }
        }
        return count;
    }
};
