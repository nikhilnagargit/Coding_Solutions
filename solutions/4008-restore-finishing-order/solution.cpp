class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_set<int> s;
        for(auto&f: friends){
            s.insert(f);
        }
        vector<int>ans;
        for(auto& i:order){
            if(s.count(i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
