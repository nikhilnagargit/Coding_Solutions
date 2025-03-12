class Solution {
public:
    int maximumCount(vector<int>& nums) {
        auto up_bnd = upper_bound(nums.begin(), nums.end(), 0);
        int first_pos_index = up_bnd - nums.begin();

        auto low_bnd = lower_bound(nums.begin(),nums.end(),0);
        int last_neg_index = low_bnd - nums.begin();

        // cout<<first_pos_index<<"," <<last_neg_index<<endl;
        int b = nums.size()-first_pos_index;
        return max(last_neg_index,b);

    }
};
