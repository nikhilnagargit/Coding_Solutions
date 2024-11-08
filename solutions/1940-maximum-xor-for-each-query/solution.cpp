class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> ans;
        int p = 1;
        while(maximumBit){
            p = p*2;
            maximumBit--;
        }
        p = p-1;


        // int result = nums[0];
        int k = nums[0]^p;
        int xori = nums[0];
        ans.push_back(k);
        for(int i=1;i<nums.size();i++){
           xori = xori^nums[i];
           ans.push_back(xori^p);
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};
