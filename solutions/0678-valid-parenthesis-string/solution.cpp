class Solution {
public:

    bool checkValidString(string s) {
        int openCount = 0 ;
        // left to right pass
        for (auto c: s){
            if(c==')'){
                openCount--;
            }
            else if(c=='(' or c=='*'){
                openCount++;
            }
            if(openCount<0) return false;
        }

        int closeCount =0 ;
        // right to left pass
        for(int i=s.size()-1;i>=0;i--){
            char c= s[i];
             if(c==')' or c=='*'){
                closeCount++;
            }
            else if(c=='('){
                closeCount--;
            }
            if(closeCount<0){
                return false;
            }
        }

        return true;
    }
};
