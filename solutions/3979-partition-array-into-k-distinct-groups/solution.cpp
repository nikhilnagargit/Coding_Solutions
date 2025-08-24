class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        if(((int)nums.size())%k!=0) return false;
        if(k==1) return true;
        unordered_map<int,int> m;
        for(auto n:nums){
            m[n]++;
        }
        for(auto item:m){
            if(item.second>((int)nums.size()/k)){
                return false;
            }
        }
        if(m.size()<k){
            return false;
        }
        return true;
    }
};
