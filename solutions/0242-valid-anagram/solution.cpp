class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        map<char,int> m;
        for(auto i:s){
            m[i]++;
        }
        for(auto j:t){
            m[j]--;
        }
        for(auto item:m){
            if(item.second!=0)
               return false;
        }
        return true;
    }
};
