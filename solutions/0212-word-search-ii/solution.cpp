class Solution {
public:
    class Node{
        public:
        string word;
        vector<Node*>next;
        Node(){
            word = "";
            next = vector<Node*>(26,nullptr);
        }
    };
    Node* root;
    void buildTrie(vector<string>& words){
        for(auto w:words){
            Node* curr = root;
            for(auto c:w){
                if(!curr->next[c-'a']){
                    curr->next[c-'a'] = new Node();
                }
                curr = curr->next[c-'a'];
            }
            curr->word = w;
        }
    }
    void dfs(vector<vector<char>>& board,Node* root,vector<string>& ans,int i,int j){

        if(root==nullptr)return;
        if(i<0 or i>=board.size() or j<0 or j>=board[0].size() or board[i][j]=='#'){
            return;
        }
        Node* curr = root;
        if(curr->next[board[i][j]-'a']==nullptr){
            return;
        }
        char cjar = board[i][j];
        board[i][j]='#';
        curr = curr->next[cjar-'a'];
        if(curr->word !=""){
            ans.push_back(curr->word);
            curr->word = "";
        }
        dfs(board,curr,ans,i+1,j);
        dfs(board,curr,ans,i,j+1);
        dfs(board,curr,ans,i-1,j);
        dfs(board,curr,ans,i,j-1);
        board[i][j] = cjar;
 
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // root node of trie
        root = new Node();
        // build the trie
        buildTrie(words);
        // initialize ans
        vector<string>ans;
        // dfs the board from all indexes
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                dfs(board,root,ans,i,j);
            }
        }
        return ans;
    }
};
