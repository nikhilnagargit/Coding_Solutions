class Solution {
public:
    bool solve(vector<vector<char>>& board,string word,int i,int j){
        if(word=="")return true;
        if(i<0 or j<0 or i>=board.size() or j>=board[0].size() or board[i][j]=='#')return false;
        char c = board[i][j];
        if(word[0]==c){
            board[i][j] = '#';
            if(solve(board,word.substr(1),i+1,j) or 
            solve(board,word.substr(1),i-1,j) or 
            solve(board,word.substr(1),i,j+1) or
            solve(board,word.substr(1),i,j-1))return true;
            board[i][j] = c;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(solve(board,word,i,j))return true;
            }
        }
    return false;    
    }
};
