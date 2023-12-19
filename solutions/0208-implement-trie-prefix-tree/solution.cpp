
class Trie {
public:
    class Node{
        public:
            bool isEnd;
            vector<Node*> children;
            Node(){
                isEnd = false;
                children = vector<Node*>(26,nullptr);
            }
    };

    Node* root;

    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* curr = root;
        for(auto c:word){
            if(curr->children[c-'a']==nullptr){
                curr->children[c-'a'] = new Node();
            }
            curr = curr->children[c-'a'];
        }
        curr->isEnd = true;
        
    }
    
    bool search(string word) {
        Node* curr = root;
        for(auto c:word){
            if(curr->children[c-'a']==nullptr){
                return false;
            }
            curr = curr->children[c-'a'];
        }
        if(curr->isEnd==false){
            return false;
        }
        return true;
    }
    
    bool startsWith(string word) {
        Node* curr = root;
        for(auto c:word){
            if(curr->children[c-'a']==nullptr){
                return false;
            }
            curr = curr->children[c-'a'];
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
