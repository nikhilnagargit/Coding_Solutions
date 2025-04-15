class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int me = nums[0];
        int ct = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==me){
                ct++;
            }
            else{
                if(ct==1){
                    me = nums[i];
                }
                else{
                    ct--;
                }
            }
        }
        return me;
    }
};
