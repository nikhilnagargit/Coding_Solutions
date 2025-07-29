class Solution {
public:
    string simplifyPath(string path) {
        string ans = "";
        string curr = "";
        vector<string> stack;
        for(int i=0;i<path.size();i++){
            if(path[i]=='/'){
                if(curr==".."){
                    if(stack.size()>=1)
                    stack.pop_back();
                }
                else if(curr=="."){

                }
                else if(curr!=""){
                    stack.push_back(curr);
                }
                curr="";
            }
            else{
                curr+= path[i];
            }
        }

       if(curr==".."){
                    if(stack.size()>=1)
                    stack.pop_back();
                }
                else if(curr=="."){

                }
                else if(curr!=""){
                    stack.push_back(curr);
                }
        
        for(auto s:stack){
            // cout<<s<<endl;
            ans+= '/'+s;
        }

        if(ans=="") return "/";
        return ans;
    }
};
