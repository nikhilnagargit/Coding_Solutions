class Solution {
public:
    int maxOperations(string s) {
        int ans = 0;
        int ones = 0;
        if(s[0]=='1') ones++;
        for(int i=1;i<s.size();i++){
            if(s[i]=='1'){
                ones++;
            }
            else if(s[i]=='0' and s[i-1]!='0'){
                ans+= ones;
            }
        }
        return ans;
    }
};
