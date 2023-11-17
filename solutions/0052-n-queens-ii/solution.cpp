class Solution {
public:
    int count;
    bool checkValid(vector<string> &board, int row, int col, int size){

        // check top up
        for(int i = row-1;i>=0; i--){
            if(board[i][col] == 'Q'){
                return false;
            }
        }

        // check diagonal
        for(int i = 1; i<=row; i++){
            if(col-i>=0){
                // left diagonal
                if(board[row-i][col-i] == 'Q'){
                    return false;
                }
            }
            if(col+i <size){
                // right diagonal
                if(board[row-i][col+i] == 'Q'){
                    return false;
                }
            }
        }
        return true;
    }


    void helper(vector<string> &board, int row, int size){
        if(row == size){
            count++;
            return;
        }

        for(int i = 0; i<size; i++){
            if(checkValid(board, row, i, size)){
                board[row][i] = 'Q';
                helper(board, row+1, size);
                board[row][i] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        string str;
        str.append(n, '.');
        vector<string> board(n, str);
        count = 0;
        helper(board, 0, n);
        return count;
    }
};
