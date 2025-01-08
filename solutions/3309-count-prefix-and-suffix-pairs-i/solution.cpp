class Solution {
public:
    bool isPrefixAndSuffix(string base, string pattern){
        if(base.size()<pattern.size()){
            return false;
        }
        if(base.substr(0,pattern.size())!=pattern){
            return false;
        }
        if(base.substr(base.size()-pattern.size(),pattern.size())!=pattern){
            return false;
        }
        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                if(isPrefixAndSuffix(words[j],words[i])){
                    count++;
                }
            }
        }
        return count;
    }
};
