class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        vector<int>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i+=2){
            int a = nums[i];
            int b = nums[i+1];
            ans.push_back(b);
            ans.push_back(a);
        }
        return ans;
    }
};
