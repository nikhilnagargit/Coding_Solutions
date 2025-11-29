class Solution {
public:
    bool isPalindrome(string& s){
        int i = 0;
        int j = s.size()-1;
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    void solve(vector<vector<string>>& ans,string& s, int i,vector<string>& v){
        if(i==s.size()){
            ans.push_back(v);
            return;
        }
        for(int k=i;k<s.size();k++){
            string curr = s.substr(i,k-i+1);
            if(isPalindrome(curr)){
                v.push_back(curr);
                solve(ans,s,k+1,v);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> v;
        vector<vector<string>> ans;
        solve(ans,s,0,v);
        return ans;
    }
};
