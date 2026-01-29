class Solution {
public:
 vector<pair<int,int>> dir;
    bool solve(vector<vector<char>>& board, int i,int j, string& word, int word_idx, vector<vector<int>>& visited){
        if(word_idx==word.size()){
            return true;
        }
        if(i<0 or i>=board.size() or j<0 or j>=board[0].size()){
            return false;
        }
        if(visited[i][j]){
            return false;
        }
       
        if(board[i][j]!=word[word_idx]){
            return false;
        }

        visited[i][j] = 1;
        for(auto d : dir){
            if(solve(board,i+d.first,j+d.second,word,word_idx+1,visited)){
                return true;
            }
        }
        visited[i][j] = 0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        // if we find not matching char, stop traversing. do this for all the cells
        dir = {{0,1},{1,0},{0,-1},{-1,0}};
        vector<vector<int>> visited(board.size(),vector<int>(board[0].size(),0));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(solve(board,i,j,word,0,visited)) return true;
            }
        }
        return false;
    }
};
