class Solution {
public:
    string decodeString(string s) {
        stack<char> char_stack;
        stack<int> num_stack;
        int i =0 ;
        while(i<s.size()){
            // cout<<i<<" "
            int num = 0;
            while(i<s.size() and s[i]-'0'>=0 and s[i]-'0'<=9){
                num = num*10 + s[i]-'0';
                i++;
            }
            if(num>0)
            num_stack.push(num);
            // cout<<num<<',';
            if(i<s.size() and s[i]=='['){
                char_stack.push('[');
                i++;
            }
            while((i<s.size()) and (s[i]-'a'>=0) and (s[i]-'a'<=26)){
                char_stack.push(s[i]);
                i++;
            }
            if(i<s.size() and s[i]==']'){
                //pop the stacks
                int num = num_stack.top();
                num_stack.pop();
                string tempstring = "";
                while(char_stack.top()!='['){

                    tempstring+= char_stack.top();char_stack.pop();
                }
                char_stack.pop();
                //reverse the tempstring
                reverse(tempstring.begin(),tempstring.end());
                //push the tempstring repetative times in the stack
                for(int k=0;k<num;k++){
                    for(char tempc:tempstring){
                        char_stack.push(tempc);
                    }
                }
                i++;
            }
        
        }

        string ans = "";
        // cout<<char_stack.top();
        while(!char_stack.empty()){
            ans+=char_stack.top();
            char_stack.pop();
        }
        reverse(ans.begin(),ans.end());
        // cout<<ans;
        return ans;
    }
};
