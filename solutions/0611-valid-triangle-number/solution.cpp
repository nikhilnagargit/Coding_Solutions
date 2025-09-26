class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count =0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int target = nums[i]+nums[j];
                int left = j+1;
                int right = nums.size()-1;
                while(left<=right){
                    int mid = left + (right-left)/2;
                    if(nums[mid]>=target){
                        right = mid-1;
                    }
                    else {
                        left = mid+1;
                    }
                }
                count += (right-j);
            }
        }
        return count;
    }
};
