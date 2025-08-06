class Solution {
public:
    vector<string> output;
    unordered_map<char,vector<char>>m = {{'2',{'a','b','c'}},{'3',{'d','e','f'}},{'4',{'g','h','i'}},{'5',{'j','k','l'}},{'6',{'m','n','o'}},{'7',{'p','q','r','s'}},{'8',{'t','u','v'}},{'9',{'w','x','y','z'}}};
    void solve(string& digits,int i,string& s){
        if(i==digits.size()){
            if(s!="")
            output.push_back(s);
            return;
        }
        for(auto c:m[digits[i]]){
            s+= c;
            solve(digits,i+1,s);
            s = s.substr(0,s.size()-1);
        }
       
    }
    vector<string> letterCombinations(string digits) {

         string s = "";
        solve(digits,0,s);
        return output;
    }
    
};
