class Solution {
public:
    int binarySearch(vector<int>& nums,int target,int left,int right){
        while(left<=right){
            int mid = left +(right-left)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        // first find the peak
        while(left<right){
            int mid = left + (right-left)/2;
            // left side sorted
            if(nums[mid]>nums[right]){
                left = mid+1;
            }
            //right side sorted
            else{
                right = mid;
            }
        }
        int peak = left;
        cout<<peak;
        int first = binarySearch(nums,target,0,peak-1);
        if(first!=-1) return first;

        int second = binarySearch(nums,target,peak,nums.size()-1);
        if(second!=-1) return second;

        return -1;
    }
};
