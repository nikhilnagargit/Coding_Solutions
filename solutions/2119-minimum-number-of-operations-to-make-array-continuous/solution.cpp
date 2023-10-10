class Solution {
public:
    int binarySearch(vector<int>& nums,int target){
        int left=0;
        int right=nums.size()-1;
        
        while(left<=right){
            int mid = left+(right-left)/2;
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
        return min(left,right);
    }

    int minOperations(vector<int>& nums) {
        // sort the array
        sort(nums.begin(),nums.end());
        int l = nums.size();
        // remove duplicates and replace by -1
        int duplicates_removed=0;
        for(int i=1;i<nums.size();i++){
            if(abs(nums[i-1])==abs(nums[i])){
                nums[i]=-1*nums[i];
                duplicates_removed++;
            }
        }
        
        // again sort the array
        sort(nums.begin(),nums.end());

        for(auto i:nums){
            cout<<i<<" ";
        }
  
        // take one by one from logical starting (non negative)
        int min_changes=INT_MAX;

        for(int i=duplicates_removed;i<nums.size();i++){
            int current = nums[i];
            int target = current+l-1;
            int target_index = binarySearch(nums,target);
            int current_changes = i+l-target_index-1;
            // cout<<"i:"<<i<<" current:"<<current<<" target:"<<target<<" tindex:"<<target_index<<"curr_chg:"<<current_changes<<endl;
            if(min_changes>current_changes){
                min_changes= current_changes;
            }
        } 

    return min_changes;
    }
};
