class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        // one possiblity - max three numbers 
        int a = nums[nums.size()-3]*nums[nums.size()-2]*nums[nums.size()-1];
        // one possiblity - maximum negative two numbers and one maximum positive number
        int b = nums[0]*nums[1]*nums[nums.size()-1];
        // when all are negative in that case -
        int c = nums[0]*nums[1]*nums[2];
        return max({a,b,c});
    }
};
