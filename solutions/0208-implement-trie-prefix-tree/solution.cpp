class TrieNode{
    public:
    bool end;
    vector<TrieNode*> v;
    TrieNode(){
        end=false;
        v = vector<TrieNode*>(26,nullptr);
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(auto& c:word){
           if(curr->v[c-'a']==nullptr){
            curr->v[c-'a'] = new TrieNode();
           }
           curr = curr->v[c-'a'];
        }
        curr->end = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(auto& c:word){
           if(curr->v[c-'a']==nullptr){
              return false;
           }
           curr = curr->v[c-'a'];
        }
        if(!curr->end){
            return false;
        }
        return true;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(auto& c:prefix){
           if(curr->v[c-'a']==nullptr){
              return false;
           }
           curr = curr->v[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
