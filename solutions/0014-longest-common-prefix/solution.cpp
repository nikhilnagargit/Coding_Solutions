class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string cp =strs[0];
        for(int i=0;i<strs.size();i++){
            string cps = "";
            for(int j=0;j<min(strs[i].size(),cp.size());j++){
                if(strs[i][j]==cp[j]){
                    cps += cp[j];
                }
                else{
                    break;
                }
            }
            cp = cps;
        }
        return cp;
    }
};
