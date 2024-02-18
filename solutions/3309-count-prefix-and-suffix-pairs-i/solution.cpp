class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                int szj = words[j].size();
                int szi = words[i].size();
                if(words[j].size()>=words[i].size() and words[i]==words[j].substr(0,words[i].size()) and words[i]==words[j].substr(szj-szi,szj)){
                    ans++;
                }
            }
        }
        return ans;
    }
};
