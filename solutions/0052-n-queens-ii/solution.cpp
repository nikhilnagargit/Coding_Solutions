class Solution {
public:
    int allRowsDone = 0;
    void solve(vector<vector<int>> board,int row){
        if(row==board.size()){
            allRowsDone++;
            return;
        }
        // put the queen in row where there is 0
        for(int col=0;col<board.size();col++){
            if(board[row][col]==0){
                vector<vector<int>> board_copy = board;
                // put queen at row, col by marking 1 
                // mark the whole col as 1
                for(int i=row;i<board.size();i++){
                    board_copy[i][col] = 1;
                }
                // mark diagonal 
                int j=0;
                for(int i=row;i<board.size();i++){
                    if(j+col<board.size()){
                        board_copy[i][col+j]=1;
                    }
                    if(col-j>=0){
                        board_copy[i][col-j]=1;
                    }
                    j++;
                }
                solve(board_copy,row+1);
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<int>> board(n,vector<int>(n,0));
        solve(board,0);
        return allRowsDone;
    }
};
