class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int>ans;
        int j=0;
        for(auto word:words){
            for(int i=0;i<word.size();i++){
                if(word[i]==x){
                    ans.push_back(j);
                    break;
                }
            }
            j++;
        }
        return ans;
    }
};
