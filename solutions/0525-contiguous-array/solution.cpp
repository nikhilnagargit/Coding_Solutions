class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // diff -> index map
        unordered_map<int,int> m;
        int zeros = 0;
        int ones = 0;
        int maxL = 0;
        m[0]=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) zeros++;
            else ones++;

            int diff = zeros - ones;

            if(m.count(diff)){
                maxL = max(maxL, i-m[diff]);
            }
            else{
                m[diff]=i;
            }
        }
        return maxL;
    }
};
