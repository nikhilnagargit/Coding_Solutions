class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        char prev = word[0];
        int idx = 1;
        int count = 1;

        if(word.size()==1){
            comp+='1';
            comp+= prev;
        }
        while(idx<word.size()){
            while(idx<word.size() and word[idx]==prev){
                idx++;
                count++;
            }
            while(count>9){
                comp += '9';
                comp+= prev;
                count = count-9;
            }
            comp+= to_string(count);
            comp+= prev;
            prev = word[idx];
            count = 0;
        }
        // comp+= to_string(count);
        // comp+= word[idx];
        
        return comp;
    }
};
