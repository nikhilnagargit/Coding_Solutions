class Solution {
public:
    vector<string> round(vector<string> v, string operation){
        if(v.size()==1)return v;
        stack<string> stk;
        int i=0;
        while(i<v.size()){
            string item = v[i];
            if(operation=="aclass" and (item[0]=='*' or item[0]=='/')){
                string a = stk.top(); stk.pop();
                string b = v[i+1];
                i++;
                if(item[0]=='/')
                stk.push(to_string(stoi(a)/stoi(b)));
                if(item[0]=='*')
                stk.push(to_string(stoi(a)*stoi(b)));
            }
            else if(operation=="bclass" and (item[0]=='+' or item[0]=='-')){
                string a = stk.top(); stk.pop();
                string b = v[i+1];
                i++;
                if(item[0]=='+')
                stk.push(to_string(stoi(a)+stoi(b)));
                if(item[0]=='-')
                stk.push(to_string(stoi(a)-stoi(b)));
            }
            else{
                stk.push(item);
            }
            i++;
        }

        vector<string> newv;
        while(!stk.empty()){
            string t = stk.top();stk.pop();
            newv.push_back(t);
        }
        reverse(newv.begin(),newv.end());
        return newv;
    }
    int calculate(string s) {
        //omit the spaces and tokenize
        vector<string> v;
        string curr = "";
        for(auto& c:s){
            if(c==' ')continue;
            if(c=='+' or c=='-' or c=='/' or c=='*'){
                v.push_back(curr);
                curr="";
                curr+= c;
                v.push_back(curr);
                curr="";
            }
            else{
                curr+=c;
            }
        }
        v.push_back(curr);


        // first round, / operation
        v = round(v,"aclass");


        v = round(v,"bclass");




        return stoi(v[0]);

    }
};
