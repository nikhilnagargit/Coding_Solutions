class Solution {
public:
    string sortVowels(string s) {
        unordered_map<char,int> freq;
        unordered_set<char>vowels = {'a','e','i','o','u','A','E','I','O','U'};
        for(int i=0;i<s.size();i++){
            if(vowels.count(s[i])){
                freq[s[i]]++;
            }
        }

        vector<int> items ;
        for(auto& item:freq){
            items.push_back(item.first);
        }
        sort(items.begin(),items.end());
        int p = 0 ;
        for(int i = 0;i<s.size();i++){
            if(vowels.count(s[i])){
                s[i]=items[p];
                freq[items[p]]--;
                if(freq[items[p]]==0){
                    p++;
                }
            }
        }
        return s;
    }
};
