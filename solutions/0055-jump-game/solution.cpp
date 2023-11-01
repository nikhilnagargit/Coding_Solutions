class Solution {
public:

    bool canJump(vector<int>& nums) {
        int max_index_reachable = 0;
        int target = nums.size()-1;
        if(nums.size()==1){
            return true;
        }
        for(int i=0;i<target;i++){
            if(max_index_reachable<i){
                return false;
            }
            if(max_index_reachable<i+nums[i]){
                max_index_reachable= i+nums[i];
            }
            if(max_index_reachable>=target){
                return true;
            }
        }
        return false;
    }
};
