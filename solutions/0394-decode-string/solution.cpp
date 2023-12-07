class Solution {
public:
    bool isDigit(char c){
        if(c-'0'>=0 and c-'0'<=9){
            return true;
        }
        return false;
    }

    string decodeString(string s) {
        stack<string> stk;
        int i=0;
        while(i<s.size()){
            if(isDigit(s[i])){
                string count = "";
                while(isDigit(s[i])){
                    count += s[i];
                    i++;
                }
                i--;
                stk.push(count);
            }

            // if there is a bracket
            else if(s[i]=='['){
                stk.push("[");
            }
            else if(s[i]==']'){
                string temp = "";
                while(!stk.empty() and stk.top()!="["){
                    temp=stk.top()+temp;
                    stk.pop();
                }
                stk.pop();
                int count = stoi(stk.top());
                stk.pop();
                string temp1 = "";
                for(int j=0;j<count;j++){
                    temp1+= temp;
                }
                stk.push(temp1);
            }
            else{
                string t = "";
                t+= s[i];
                stk.push(t);
            }
            i++;
        }
        string ans = "";
        while(!stk.empty()){
            ans = stk.top()+ans;
            stk.pop();
        }
     return ans;
    }
};
