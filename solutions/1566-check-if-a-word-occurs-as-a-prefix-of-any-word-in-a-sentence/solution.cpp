class Solution {
public:
    bool checkPrefix(string& w,string& search){
        if(search.size()>w.size()){
            return false;
        }
        for(int i=0;i<search.size();i++){
            if(search[i]!=w[i]){
                return false;
            }
        }
        return true;
    }

    int isPrefixOfWord(string sentence, string searchWord) {
        string curr_word = "";
        int word_number = 1;

        for(char c: sentence){
            if(c==' '){
                // cout<<curr_word<<" ";
                //check if prefix is there
                if(checkPrefix(curr_word,searchWord)){
                    return word_number;
                }
                curr_word = "";
                word_number++;
                continue;
            }
            curr_word += c;
        }

        // cout<<curr_word;
        if(checkPrefix(curr_word,searchWord)){
            return word_number;
        }

        return -1;
    }
};
