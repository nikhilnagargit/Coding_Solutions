class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(mid-1>=0 and nums[mid]==nums[mid-1]){
                if(mid%2==0){
                    //left section
                    right = mid-1;
                }
                else{
                    left = mid+1;
                }
            }
            else if(mid-1>=0 and nums[mid]!=nums[mid-1]){
                if(mid%2==0){
                    left = mid+1;
                }
                else{
                    right= mid-1;
                }
            }
            else{
                left = mid+1;
                break;
            }
        }
        return nums[left-1];
    }
};
