class Solution {
public:
        vector<vector<int>> rows;
        vector<vector<int>> cols;
        vector<vector<int>> boxes;

    bool solve(vector<vector<char>>& board,int i,int j){
        if(i==board.size()){
            return true;
        }
        if(board[i][j]!='.'){
            j++;
            if(j==9){
                i++;
                j=0;
            }
            return solve(board,i,j);
        }

        for(int num = 1;num<=9;num++){
            //check if we can put num
            if(rows[i][num-1]+ cols[j][num-1] + boxes[3*(i/3) + j/3][num-1] != 0){
                continue;
            }
            int prevrows = rows[i][num-1] ;
            int prevcols = cols[j][num-1] ;
            int prevboxes = boxes[3*(i/3) + j/3][num-1] ;    
            //put the num at current
            rows[i][num-1] = 1;
            cols[j][num-1] = 1;
            boxes[3*(i/3) + j/3][num-1] = 1;
            board[i][j] = (char)('0'+num);

            //sovle for next
            int newj = j+1;
            int newi = i;
            if(newj==9){
                newi++;
                newj=0;
            }
            bool result = solve(board,newi,newj);
            if(result) return true;
            //backtrack and reset prev values
            rows[i][num-1] = prevrows;
            cols[j][num-1] = prevcols;
            boxes[3*(i/3) + j/3][num-1] = prevboxes;
            board[i][j]='.';
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        rows = vector<vector<int>>(9, vector<int>(9, 0));
        cols = vector<vector<int>>(9, vector<int>(9, 0));
        boxes = vector<vector<int>>(9, vector<int>(9, 0));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]!='.'){
                    int d = board[i][j]-'0';
                    rows[i][d-1] = 1;
                    cols[j][d-1] = 1;
                    boxes[3*(i/3) + j/3][d-1] = 1;
                }
            }
        }
        solve(board,0,0);
    }
};
