class Solution {
public:
    int lengthOfLastWord(string s) {
        string currword = "";
        int i=s.size()-1;
        int l = 0;
        while(s[i]==' '){
            i--;
        }
        while(i>=0 and s[i]!=' '){
            l++;
            i--;
        }
        return l;
    }
};
