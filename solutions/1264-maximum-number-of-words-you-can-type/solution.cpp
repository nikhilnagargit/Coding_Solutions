class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        text = text+" ";
       vector<int> brokenv(26,0);
       for(auto& b:brokenLetters){
        brokenv[b-'a'] =1;
       } 
       int count = 0;
       bool skip = false;
       string word = "";

       for(int i=0;i<text.size();i++){
        if(text[i]==' '){
            word = "";
            if(!skip){
                count++;
            }
            skip = false;
        }
        else{
            if(brokenv[text[i]-'a']==1){
                skip = true;
            }
            word+= text[i];
        }
       }
       return count;

    }
};
