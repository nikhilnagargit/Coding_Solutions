class Solution {
public:

    int binarySearchStart(vector<int>& nums,int left,int right,int target){
      if(left>right){
        return -1;
      }
      int mid = left + (right-left)/2;
      
      if(mid==0 and nums[mid]==target){
        return mid;
      }
      else if(mid==0 and nums[mid]>target){
        return -1;
      }
      else if(mid==0 and nums[mid]<target){
        return binarySearchStart(nums,mid+1,right,target);
      }

      if(nums[mid]==target and nums[mid-1]!=target){
        return mid;
      }
      else if(nums[mid]==target and nums[mid-1]==target){
        return binarySearchStart(nums,left,mid-1,target);
      }
      else if(nums[mid]>target){
        return binarySearchStart(nums,left,mid-1,target);
      }
      else{
       return binarySearchStart(nums,mid+1,right,target);
      }
      return -1;
    }


        int binarySearchEnd(vector<int>& nums,int left,int right,int target){
      if(left>right){
        return -1;
      }
      int mid = left + (right-left)/2;
      if(mid==nums.size()-1 and nums[mid]==target){
        return mid;
      }
      else if(mid==nums.size()-1 and nums[mid]!=target){
        return -1;
      }
      if(nums[mid]==target and nums[mid+1]!=target){
        return mid;
      }
      else if(nums[mid]==target and nums[mid+1]==target){
        return binarySearchEnd(nums,mid+1,right,target);
      }
      else if(nums[mid]>target){
        return binarySearchEnd(nums,left,mid-1,target);
      }
      else{
       return binarySearchEnd(nums,mid+1,right,target);
      }
      return -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
       if(nums.size()==0){
         return vector<int>({-1,-1});
       }
        int start = binarySearchStart(nums,0,nums.size()-1,target);
        int end = binarySearchEnd(nums,0,nums.size()-1,target);
        vector<int> m ({start,end});

        return m;
    }
};
