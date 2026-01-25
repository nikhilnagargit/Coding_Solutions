class Solution {
public:
    bool isCapital(char c){
        if( c>='A' and c<='Z' ) return true;
        return false;
    }

    bool check(string s, string pattern){
        int i=0;
        for(int idx=0;idx<pattern.size();idx++){
            char p = pattern[idx];
            // for each char in pattern, make sure it fullfils the s
            while(i<s.size()){
                if(isCapital(s[i]) and  s[i]!=p){
                    return false;
                }
                if(s[i]==p){
                    // matching done, so skip to match next pattern char
                    i++;
                    break;
                }
                i++;      
                if(i==s.size()) return false;      
            }
            if(i==s.size() and idx!=pattern.size()-1) return false;  
        }
        while(i<s.size()){
            if(isCapital(s[i])) return false;
            i++;
        }
        return true; 
    }

    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        for(auto& q: queries){
            ans.push_back(check(q,pattern));
        }
        return ans;
    }
};
