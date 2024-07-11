class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> stk;
        for(char c :s){
            if(c==')'){
                string temp = "";
                while(!stk.empty() && stk.top()!='('){
                    temp+= stk.top();
                    stk.pop();
                }
                //pop the ( 
                stk.pop();
                // reverse the string and push again
                // reverse(temp.begin(),temp.end());
                // cout<<temp<<endl;
                for(char ch:temp){
                    stk.push(ch);
                }
            }
            else{
                stk.push(c);
            }
        }
        string ans = "";
        while(!stk.empty()){
                    ans+= stk.top();
                    stk.pop();
                }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
