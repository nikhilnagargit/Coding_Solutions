class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s=="")return true;
        if(s.size()>t.size())return false;
        int i=0;
        int j=0;
        while(i<t.size()){
            if(s[j]==t[i]){
                j++;
            }
            if(j==s.size()){
            return true;
            }
            i++;
        }

return false;
    }
};
