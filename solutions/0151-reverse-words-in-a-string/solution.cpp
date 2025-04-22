class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string word  = "";
        int i=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                if(word!=""){
                words.push_back(word);
                // cout<<","<<word<<",";
                }
                word = "";
            }
            else{
                word += s[i];
            }
        }
        if(word!="")
        words.push_back(word);
        string ans="";
        reverse(words.begin(),words.end());
        for(int i=0;i<words.size();i++){
            ans+= words[i];
            if(i!=words.size()-1){
                ans+=" ";
            }
        }
        return ans;
    }
};
