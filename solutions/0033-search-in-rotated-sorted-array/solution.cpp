class Solution {
public:
    int binary_search(vector<int>& nums,int target,int left,int right){
        if(nums[0]==target)return 0;
        
        while(left<=right){
            int mid = left + (right-left)/2;
            if(nums[mid]==target)return mid;
            else if(nums[mid]<target){
                left = mid+1;
            }
            else right = mid-1;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        if(nums.size()==1 and nums[0]==target)return 0;
        if(nums.size()==1 and nums[0]!=target)return -1;
        

        int left = 1;
        int right = nums.size()-2;
        int mid;
        if(nums[0]>nums[1]){
            mid = 0;
        }
        else if(nums[nums.size()-1]<nums[nums.size()-2]){
            mid = nums.size()-2;
        }
        else{
        while(left<=right){
            mid = left+(right-left)/2;
            if(nums[mid]>nums[mid+1]){
                break;
            }
            else if(nums[mid]>nums[0]){
                left = mid+1;
            }
            else if(nums[mid]<nums[0]){
                right = mid-1;
            }
            else{
                break;
            }
        }
        }

        int first = binary_search(nums,target,0,mid);
        if(first!=-1) return first;
        if(mid+1<=nums.size()-1){        
        int second = binary_search(nums,target,mid+1,nums.size()-1);
        return second;
        }
        return -1;
    }
};
