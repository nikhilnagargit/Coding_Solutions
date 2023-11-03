class Node{
    public:
    Node* links[26];
    bool flag = false;
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* curr = root;
        for(int i=0;i<word.length();i++){
            char c = word[i];
            if(curr->links[c-'a']==NULL)
                curr->links[c-'a'] = new Node();
            curr = curr->links[c-'a'];
        }
        curr->flag = true;
    }
    
    bool search(string word) {
        Node* curr = root;
        for(int i=0;i<word.length();i++){
            char c = word[i];
            if(curr->links[c-'a']==NULL){
                return false;
            }
            curr = curr->links[c-'a'];
        }
        if(curr->flag==false){
            return false;
        }
        return true;
    }
    
    bool startsWith(string word) {
                Node* curr = root;
        for(int i=0;i<word.length();i++){
            char c = word[i];
            if(curr->links[c-'a']==NULL){
                return false;
            }
            curr = curr->links[c-'a'];
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
