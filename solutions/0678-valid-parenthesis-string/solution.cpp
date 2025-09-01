class Solution {
public:
    bool checkValidString(string s) {
        int opencount = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' or s[i]=='*'){
                opencount+=1;
            }
            else if(s[i]==')'){
                opencount-=1;
            }
            if(opencount<0){
                return false;
            }
        }
        int closecount = 0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==')' or s[i]=='*'){
               closecount+=1;
            }
            else if(s[i]=='('){
                closecount-=1;
            }
            if(closecount<0){
                return false;
            }
        }
        return true;
    }
};
