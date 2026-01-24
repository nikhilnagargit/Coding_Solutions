class Solution {
public:
    bool isValid(string part){
        if(part.size()>1 and part[0]=='0') return false;
        if(stoi(part)<256)return true;
        return false;
    }
    void solve(string& s, int i, int dots, string prefix,vector<string>& ans){
        // base case
        if(dots==4 and i==s.size()){
            // success
            ans.push_back(prefix.substr(0,prefix.size()-1));
            return;
        }
        if(dots>4){
            return;
        }
        for(int j=0;j<3;j++){
            // three digits we are gonna take and check if they are valid
            if(i+j>=s.size()){
                break;
            }
            string part = s.substr(i,j+1);
            if(isValid(part)){
                solve(s,i+j+1,dots+1,prefix+part+".",ans);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        if(s.size()>12 or s.size()<4) return ans;
        int dots = 0;
        string prefix = "";
        solve(s,0,dots,prefix,ans);
        return ans;
    }
};
