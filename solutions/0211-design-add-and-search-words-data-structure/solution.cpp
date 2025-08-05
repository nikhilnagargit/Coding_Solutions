class TrieNode{
    public:
    unordered_map<char,TrieNode*> m;
    bool end;
    TrieNode(){
        end = false;
    }
};


class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr= root;
        for(char& c:word){
            if(curr->m.count(c)==0){
                curr->m[c]=new TrieNode();
            }
            curr = curr->m[c];
        }
        curr->end = true;
    }
    bool traverse(TrieNode* root,string word,int idx){
        if(word.size()==idx and root->end){
            return true;
        }
        if(word.size()==idx)
            return false;
        char c = word[idx];
        if(c=='.'){
            for(auto& item:root->m){
                if(traverse(item.second,word,idx+1)) return true;
            }
        }
        else{
            if(root->m.count(c)){
                if(traverse(root->m[c],word,idx+1)) return true;
            }
            else{
                return false;
            }
        }
        return false;
    }

    bool search(string word) {
        return traverse(root,word,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
