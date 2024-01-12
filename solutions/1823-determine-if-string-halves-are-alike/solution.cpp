class Solution {
public:
    bool halvesAreAlike(string s) {
        int count1  = 0;
        int count2 = 0;
        unordered_set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
        int half = s.size()/2;
        for(int i=0;i<half;i++){
            if(vowels.find(s[i])!=vowels.end()){
                count1++;
            }
        }
        for(int i=half;i<s.size();i++){
            if(vowels.find(s[i])!=vowels.end()){
                count2++;
            }
        }
        return count1==count2;
    }
};
