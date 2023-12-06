class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_set<int>s;
        unordered_map<int,int>m;
        for(auto i:arr){
            m[i]++;
        }
        for(auto item:m){
            if(s.find(item.second)!=s.end()){
                return false;
            }
            s.insert(item.second);
        }
        return true;
    }
};
