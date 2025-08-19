class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' or s[i]=='{' or s[i]=='['){
                stk.push(s[i]);
            }
            else if(s[i]==')'){
                if(stk.empty() or stk.top()!='(') return false;
                stk.pop();
            }
            else if(s[i]==']'){
                if(stk.empty() or stk.top()!='[') return false;
                stk.pop();
            }
            else if(s[i]=='}'){
                if(stk.empty() or stk.top()!='{') return false;
                stk.pop();
            }
        }
        if(!stk.empty()) return false;
        return true;
    }
};
