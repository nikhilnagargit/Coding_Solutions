class Solution {
public:
    int maxFreqSum(string s) {
        unordered_set<char> vowels = {'a','e','i','o','u'};
        vector<int> v(26,0);
        for(auto& c:s){
            v[c-'a']++;
        }
        int maxv = 0;
        int maxc = 0;
        for(int i=0;i<26;i++){
            if(vowels.count(char('a'+i))){
                maxv = max(maxv,v[i]);
            }
            else{
                maxc = max(maxc,v[i]);
            }
        }
        return maxv+maxc;
    }
};
