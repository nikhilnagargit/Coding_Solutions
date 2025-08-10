class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int and_product = INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(i!=nums[i]){
                and_product = and_product&nums[i];
            }
        }
        if(and_product==INT_MAX) return 0;
        return and_product;
    }
};
