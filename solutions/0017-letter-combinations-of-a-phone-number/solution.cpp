class Solution {
public:
    vector<string> mapping;
    Solution(){
        mapping = vector<string>(10,"");
        mapping[2] = "abc"; 
        mapping[3] = "def"; 
        mapping[4] = "ghi"; 
        mapping[5] = "jkl"; 
        mapping[6] = "mno"; 
        mapping[7] = "pqrs"; 
        mapping[8] = "tuv"; 
        mapping[9] = "wxyz"; 
    }

    void solve(string& digits,string& s,vector<string>&ans,int i){


        if(s.size()==digits.size()){
            ans.push_back(s);
            return;
        }
        string s_backup = s;
        // cout<<int(digits[i]-'0');
        string m = mapping[int(digits[i]-'0')];
        for(int j=0;j<m.size();j++){
            s+=m[j];
            solve(digits,s,ans,i+1);
            s=s_backup;
        }
        return ;
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0){
            return vector<string>(0);
        }
        vector<string>ans;
        string s = "";
        solve(digits,s,ans,0);
        return ans;         
    }
};
