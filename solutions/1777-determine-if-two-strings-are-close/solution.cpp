class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        if(n1!=n2)return false;

        unordered_set<char> s1(word1.begin(),word1.end()), s2(word2.begin(),word2.end());
        if(s1!=s2) return false;
        
        unordered_map<char,int> m1,m2;
        for(char c:word1){
            m1[c]++;
        }
        for(char c:word2){
            m2[c]++;
        }
        vector<int> v1,v2;
        for(auto item:m1){
            v1.push_back(item.second);
        }
        for(auto item:m2){
            v2.push_back(item.second);
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        if(v1!=v2)return false;

        return true;
    }
};
