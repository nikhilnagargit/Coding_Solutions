class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int x = 0 ;
        int count = 0;
        for(auto i:nums){
            if(x+i==0){
                count++;
            }
            x = x+i;
        }
        return count;
    }
};
