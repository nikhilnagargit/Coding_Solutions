class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word,int idx,int i,int j,vector<vector<int>>& visited){
                if(idx==word.size()){
            return true;
        }
        if(i<0 or j<0 or i>=board.size() or j>=board[0].size()){
            return false;
        }

        if(visited[i][j]){
            return false;
        }
        if(word[idx]!=board[i][j])return false;

        visited[i][j]=1;
        if(dfs(board,word,idx+1,i+1,j,visited)) return true;
        if(dfs(board,word,idx+1,i,j+1,visited)) return true;
        if(dfs(board,word,idx+1,i-1,j,visited))return true;
        if(dfs(board,word,idx+1,i,j-1,visited))return true;
        visited[i][j]=0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> visited(board.size(),vector<int>(board[0].size(),0));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(dfs(board,word,0,i,j,visited)) return true;
            }
        }
        return false;
    }
};
