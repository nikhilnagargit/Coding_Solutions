class Solution {
public:
    bool solve(string& pattern,int i,string& ans,vector<int>& included){
        if(i==pattern.size()){
            return true;
        }
        for(int n=1;n<=9;n++){
            if(included[n]==1){
                continue;
            }
            int last = ans[ans.size()-1]-'0';
            if(pattern[i]=='I' and n>last){
                ans = ans + to_string(n);
                included[n]=1;
                if(solve(pattern,i+1,ans,included)){
                    return true;
                }
                included[n]=0;
                ans.pop_back();
            }
            else if(pattern[i]=='D' and n<last){
                ans = ans + to_string(n);
                included[n]=1;
                if(solve(pattern,i+1,ans,included)){
                    return true;
                }
                included[n]=0;
                ans.pop_back();
            }
        }
        return false;
    }

    string smallestNumber(string pattern) {
        vector<int> included = {0,0,0,0,0,0,0,0,0,0};
        string ans = "";
        for(int i=1;i<=9;i++){
            included[i]=1;
            ans+= to_string(i);
            if(solve(pattern,0,ans,included)){break;}
            ans="";
            included[i]=0;
        }
        return ans;
    }
};
