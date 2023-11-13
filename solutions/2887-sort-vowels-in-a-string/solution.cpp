class Solution {
public:
    string sortVowels(string s) {
        vector<int> vowel_indexes;
        vector<int> vowels;
        set<char>V = {'a','A','e','E','i','I','O','o','u','U'}; 
        for(int i=0;i<s.size();i++){
            if(V.find(s[i])!=V.end()){
                vowel_indexes.push_back(i);
                vowels.push_back(s[i]);
            }
        }
        sort(vowels.begin(),vowels.end());
        for(int i=0;i<vowel_indexes.size();i++){
            s[vowel_indexes[i]] = vowels[i];
        }
        return s;
    }
};
