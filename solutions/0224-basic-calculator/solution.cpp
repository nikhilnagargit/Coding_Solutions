class Solution {
public:
    int calculate(string s) {
        stack<string> stk;
        int i=0;
        while(i<s.size()){
            if(s[i]==' '){
            }
            else if(s[i]=='+'){
                stk.push("+");
            }
            else if(s[i]=='-'){
                stk.push("-");
            }
            else if((s[i]-'0'<=9) and (s[i]-'0'>=0)){
                string curr = "";
                while(i<s.size() and (s[i]-'0'<=9) and (s[i]-'0'>=0)){
                    curr+= s[i];
                    i++;
                }
                stk.push(curr);
                i--;
            }
            else if(s[i]=='('){
                stk.push("(");
            }
            else if(s[i]==')'){
                int result = 0;
                while(stk.top()!="("){
                    if(stk.top()=="+"){
                        stk.pop();
                    }
                    int num = stoi(stk.top());
                    stk.pop();
                    if(stk.top()!="-"){
                        num = num;
                    }
                    else{
                        stk.pop();
                        num = num*-1;
                    }
                    result+= num;
                }
                stk.pop();
                stk.push(to_string(result));
            }
            i++;
        }

        // string p =  "";
        // while(!stk.empty()){
        //    cout<<stk.top();
        //     stk.pop();
        // }
       
        int result = 0 ;
                while(!stk.empty()){
                    if(stk.top()=="+"){
                        stk.pop();
                    }
                    int num = stoi(stk.top());
                    stk.pop();
                    if(!stk.empty()){
                    if(stk.top()!="-"){
                        num = num;
                    }
                    else{
                        stk.pop();
                        num = num*-1;
                    }
                    }
                    result+= num;
                }

        return result;
    }
};
