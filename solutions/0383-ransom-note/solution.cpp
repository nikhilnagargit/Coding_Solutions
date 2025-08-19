class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> m;
        for(auto& c:magazine){
            m[c]++;
        }
        for(auto&c: ransomNote){
            if(m.find(c)==m.end()) return false;
            if(m[c]==0) return false;
            m[c]--;
        }
        return true;
    }
};
