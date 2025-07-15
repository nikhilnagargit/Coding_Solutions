class Solution {
public:
    bool isValid(string word) {
        unordered_set<int> digits = {1,2,3,4,5,6,7,8,9,0};
        unordered_set<int> vowels = {'a','e','i','o','u','A','E','I','O','U'};

        int vcount = 0;
        int ncount = 0;
        if(word.size()<3){
            return false;
        }

        for(auto c: word){

            if(c>='0' and c<='9'){
                ncount++;
                continue;
            }
            else if(c>='a' and c<='z'){
                if(vowels.count(c)){
                    vcount++;
                }
                continue;
            }
            else if(c>='A' and c<='Z'){
                if(vowels.count(c)){
                    vcount++;
                }
                continue;
            }
            else{
                return false;
            }
        }
        if(vcount==0){
            return false;
        }
        if(word.size()-vcount-ncount==0){
            return false;
        }
        return true;
    }
};
