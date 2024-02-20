class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xorp= 0;
        for(int i=1;i<=nums.size();i++)
         xorp = xorp^i;
        
        for(auto i:nums){
            xorp = xorp^i;
        }
        return xorp;

       }
};
