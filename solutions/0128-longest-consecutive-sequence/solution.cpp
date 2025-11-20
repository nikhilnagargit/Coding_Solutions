class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(auto&n : nums){
            s.insert(n);
        }
        int maxl = 0;
        for(auto& n: s){
            if(s.count(n-1)){
                continue;
            }
            int l = 1;
            int k = n;
            while(s.count(k+1)){
                k = k+1;
                l++;
            }
            maxl = max(maxl,l);
        }
        return maxl;
    }
};
