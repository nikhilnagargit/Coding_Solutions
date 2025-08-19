class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())return false;
        unordered_map<char,int>s1,s2;
        for(auto& c:s) s1[c]++;
        for(auto& c:t) s2[c]++;
        return s1==s2;
    }
};
