class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for(auto item:tokens){
            if(item=="*"){
                int one = s.top();
                s.pop();
                int two  = s.top();
                s.pop();
                s.push(one*two);
            }
            else if(item=="+"){
                int one = s.top();
                s.pop();
                int two  = s.top();
                s.pop();
                s.push(one+two);
            }
            else if(item=="-"){
                int one = s.top();
                s.pop();
                int two  = s.top();
                s.pop();
                s.push(two-one);
            }
            else if(item=="/"){
                int one = s.top();
                s.pop();
                int two  = s.top();
                s.pop();
                s.push(two/one);
            }
             else{
                s.push(stoi(item));
            }
        }
        return s.top();
    }
};
