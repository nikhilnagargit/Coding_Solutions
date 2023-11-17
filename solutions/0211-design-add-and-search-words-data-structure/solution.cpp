class WordDictionary {
public:
    class Node{
        public:
        bool isEnd;
        vector<Node*>children;
        Node(){
            isEnd = false;
            children = vector<Node*>(26,nullptr);
        }
    };
    Node* root;
    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {
        Node* curr = root;
        for(int i=0;i<word.size();i++){
            if(!curr->children[word[i]-'a']){
                curr->children[word[i]-'a'] = new Node();
            }
            curr = curr->children[word[i]-'a'];
        }    
        curr->isEnd = true;
    }
    
    bool solve(string word,Node* curr){
        if(curr==nullptr) return false;
        if(word=="" and curr->isEnd)return true;

        for(int i=0;i<word.size();i++){
            char c = word[i];
            if(c=='.'){
                for(int j=0;j<26;j++){
                    if(curr->children[j]&&solve(word.substr(i+1),curr->children[j]))
                        return true;
                }
                return false;
            }
            else{
                if(curr->children[c-'a']==nullptr){
                    return false;
                }
                curr = curr->children[c-'a'];
            }
          }
          if(curr->isEnd==true)return true;
          return false;
    }

    bool search(string word) {
        Node* curr = root;
        return solve(word,root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
