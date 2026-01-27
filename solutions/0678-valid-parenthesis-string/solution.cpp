class Solution {
public:
    bool checkValidString(string s) {
        int openCount = 0 ;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' or s[i]=='*') openCount++;
            else openCount--;
            if(openCount<0) return false;
        }
        int closeCount =0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==')' or s[i]=='*') closeCount++;
            else closeCount--;
            if(closeCount<0) return false;
        }
        return true;
    }
};
