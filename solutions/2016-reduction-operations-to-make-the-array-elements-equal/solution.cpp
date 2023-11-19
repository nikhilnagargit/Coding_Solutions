class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        map<int,int>m;
        for(auto i:nums){
            m[i]++;
        }
        int ans = 0;
        while(m.size()!=1){
            int key = m.rbegin()->first;
            int value = m[key];
            ans+=value;
            m.erase(key);
            int nextkey = m.rbegin()->first;
            m[nextkey] += value;
        }
        return ans;
    }
};
