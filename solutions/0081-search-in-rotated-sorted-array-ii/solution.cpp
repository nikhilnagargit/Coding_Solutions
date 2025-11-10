class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while(left<=right){
            int mid = left + (right-left)/2;

            if(nums[mid]==target){
                return true;
            }

            if(nums[mid]==nums[left]){
                left++;
                continue;
            }

            //if first part is in order
            if(nums[left]<=nums[mid]){

                //targaet lies in first part
                if(target<=nums[mid] and target>=nums[left]){
                    right = mid-1;
                }
                else{
                    left = mid+1;
                }

            }
            // if second part is in order
            else{
                //targaet lies in second part
                if(target>=nums[mid] and target<=nums[right]){
                    left = mid+1;
                }
                else{
                    right = mid-1;
                }
            }
        }
        return false;
    }
};
