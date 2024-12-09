class Solution {
public:
// [1,0,1,0,0]
// [0,1,1,0]

    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> prefix(nums.size(),0);
        prefix[0] = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]%2==0 and nums[i-1]%2==0){
                prefix[i] = 1;
            }
            else if(nums[i]%2==0 and nums[i-1]%2!=0){
                prefix[i] = prefix[i-1]+1;
            }
            else if(nums[i]%2!=0 and nums[i-1]%2==0){
                prefix[i] = prefix[i-1]+1;
            }
            else{
                prefix[i] = 1;
            }
        }
        vector<bool>ans;
        for(auto& q:queries){
            if(prefix[q[1]]>(q[1]-q[0])){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};
