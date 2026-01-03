class Solution {
public:
    string reversePrefix(string s, int k) {
        string ans = "";
        for(int i=0;i<s.size();i++){
            if(i<k)
            ans = s[i]+ans;
            else
                ans+= s[i];
        }
        return ans;
    }
};
