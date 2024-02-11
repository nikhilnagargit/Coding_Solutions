class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        int i =0 ;
        int lastlen  = 0;
        while(i<s.size()){
            len = 0;
            while(i<s.size() and s[i]!=' '){
                len++;
                i++;
                
            }
            if(len!=0)lastlen = len;
            i++;
        }
        return lastlen;
    }
};
