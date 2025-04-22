class Solution {
public:
    int lengthOfLastWord(string s) {
        string lastword = "";
        string currword = "";
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                if(currword!="" and currword!=" ")
                lastword = currword;
                currword = "";
            }
            else {
                currword+= s[i];
            }
        }
        if(currword!="" and currword!=" ")
            lastword = currword;

        // cout<<","<<lastword<<",";
        return lastword.size();
    }
};
