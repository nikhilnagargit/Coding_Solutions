class Solution {
public:
    string makeFancyString(string s) {
        if(s.size()<=2){
            return s;
        }
        int curr = 2;
        string ans  = "";
        ans+= s[0];
        ans+= s[1];

        for(int i=2;i<s.size();i++){
            if(s[curr-1]!=s[curr] or s[curr-2]!=s[curr])
                ans+= s[curr];
            curr++;
        }
        return ans;
    }
};
