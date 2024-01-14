class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxfrq = 0;
        unordered_map<int,int>m;
        for(auto i:nums){
            m[i]++;
            maxfrq = max(maxfrq,m[i]);
        }
        int ans = 0;
        for(auto i:m){
            if(i.second==maxfrq){
                ans+= i.second;
            }
        }
        return ans;
    }
};
