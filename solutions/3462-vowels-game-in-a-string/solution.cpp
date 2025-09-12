class Solution {
public:
    bool doesAliceWin(string s) {
        unordered_set<char> vowels = {'a','e','i','o','u'};
        int count = 0;
        for(auto& c:s){
            if(vowels.count(c)){
                return true;
            }
        }

            return false;

    }
};
