class TrieNode{
        public:
        bool isEnd;
        vector<TrieNode*> v;
        TrieNode(){
            isEnd = false;
            v = vector<TrieNode*>(26,nullptr);
        }
    };

class Trie{
    public:
        TrieNode* root ;
        Trie(){
            root = new TrieNode();
        }
        bool searchWord(string word){
        TrieNode* curr = root;
        for(auto& c:word){
            if(curr->v[c-'a']==nullptr){
                return false;
            }
            curr = curr->v[c-'a'];
        }
        if(!curr->isEnd) return false;
        return true;
        }

        bool searchPrefix(string word){
        TrieNode* curr = root;
        for(auto& c:word){
            if(curr->v[c-'a']==nullptr){
                return false;
            }
            curr = curr->v[c-'a'];
        }
        return true;
        }

        void insert(string word){
            TrieNode* curr = root;
            for(auto& c:word){
                if(curr->v[c-'a']==nullptr){
                    curr->v[c-'a']=new TrieNode();
                }
                curr = curr->v[c-'a'];
            }
            curr->isEnd = true;
        }

};

class Solution {
public:
    unordered_set<string> ans;
    void dfs(vector<vector<char>>& board,int i,int j,TrieNode* root,vector<vector<int>>& visited,string word){
        if(i<0 or i>=board.size() or j<0 or j>=board[0].size()){
            return;
        }
        if(visited[i][j]){
            return;
        }
        if(root->v[board[i][j]-'a']==nullptr){
           return;
        }
        
        root = root->v[board[i][j]-'a'];
        visited[i][j]=1;
        word += board[i][j];
        if (root->isEnd) ans.insert(word);
        dfs(board,i+1,j,root,visited,word);
        dfs(board,i,j+1,root,visited,word);
        dfs(board,i-1,j,root,visited,word);
        dfs(board,i,j-1,root,visited,word);
        visited[i][j]=0;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* trie = new Trie();
        for(auto w:words){
            trie->insert(w);
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                vector<vector<int>> visited(board.size(),vector<int>(board[0].size(),0));
                dfs(board,i,j,trie->root,visited,"");
            }
        }
        return vector<string>(ans.begin(),ans.end());
    }
};
