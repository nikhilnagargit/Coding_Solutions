class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        int idx = 0;
        for(int i=0;i<s.size();i++){
            if(idx<spaces.size() and i==spaces[idx]){
                ans+=" ";
                ans+=s[i];
                idx++;
            }
            else{
                ans+=s[i];
            }
        }
        return ans;
    }
};
