class Solution {
public:
    int solve(vector<int>& nums,int target, int left, int right){
        
        if(left>right){
            return -1;
        }
        if(left<0 or left>=nums.size()){
            return -1;
        }
        if(right<0 or right>=nums.size()){
            return -1;
        }
        int mid = (left+right)/2;
        
        if(nums[mid]==target){
            return mid;
        }
        
        if(nums[mid]<target){
            return solve(nums,target,mid+1,right);
        }
        
        if(nums[mid]>target){
            return solve(nums,target,left,mid-1);
        }
        
        return mid;
    }
    
    int search(vector<int>& nums, int target) {
        int index = solve(nums,target,0,nums.size()-1);
        return index;
    }
};
