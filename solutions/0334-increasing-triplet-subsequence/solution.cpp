class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size()<3){
            return false;
        }
        int left = INT_MAX;
        int mid = INT_MAX;
        for(int i=0;i<nums.size();i++){
            int curr= nums[i];
            if(curr<=left){
                left = curr;
            }
            else if(curr<=mid){
                mid = curr;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
