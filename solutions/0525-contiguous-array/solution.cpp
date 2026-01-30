class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ones = 0;
        int zeros = 0;
        int maxLen = 0;
        unordered_map<int,int> m;
        m[0]=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) zeros++;
            else ones++;
            int key = ones-zeros;
            if(m.find(key)!=m.end()){
                maxLen = max(maxLen,i-m[key]);
            }
            else{
                m[key]=i;
            }
        }
        return maxLen;
    }
};
