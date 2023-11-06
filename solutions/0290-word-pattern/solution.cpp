class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char,string> m;
        unordered_set<string> myset;

        int i=0;
        int j=0;
        while(i<s.size() and j<pattern.size()){
            string word = "";
            while(i<s.size() and s[i]!=' '){
                word+=s[i];
                i++;}
            if(m.find(pattern[j])==m.end()){
                if(myset.find(word)!=myset.end()){
                    return false;
                }
                m[pattern[j]]=word;
                myset.insert(word);
            }
            else{
                if(m[pattern[j]]!=word){
                    return false;
                }
            }
            i++;
            j++;
        }
        cout<<i<<","<<s.size();
        cout<<endl;
        cout<<j<<","<<pattern.size();
        if(i!=s.size()+1 or j!=pattern.size())
        return false;

        return true;
    }
};
