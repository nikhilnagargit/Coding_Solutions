class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int leftsum  = 0 ;
        int n = nums.size();
        int rightsum = accumulate(nums.begin(), nums.end(), 0);
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            rightsum = rightsum-nums[i];
            leftsum = leftsum+nums[i];
            int result = rightsum-(n-1-i)*nums[i]+(i+1)*nums[i]-leftsum;
            ans.push_back(result);  
        }
        return ans;
    }
};
