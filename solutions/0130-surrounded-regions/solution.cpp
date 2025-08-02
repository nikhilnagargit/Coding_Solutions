class Solution {
public:
    void printBoard(vector<vector<char>>& board){
        int m = board[0].size();
        int n = board.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<board[i][j]<<",";
            }
            cout<<endl;
        }
        cout<<"------------------"<<endl;
    }
    void convertToY(vector<vector<char>>& board,int i,int j){
        if(i<0 or i>=board.size() or j<0 or j>=board[0].size()){
            return;
        }
        if(board[i][j]=='Y' or board[i][j]=='X'){
            return;
        }
        board[i][j]='Y';
        convertToY(board,i+1,j);
        convertToY(board,i,j+1);
        convertToY(board,i-1,j);
        convertToY(board,i,j-1);
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        //horizontal
        for(int j=0;j<m;j++){
            if(board[0][j]=='O'){
                convertToY(board,0,j);
            }
            if(board[n-1][j]=='O'){
                convertToY(board,n-1,j);
            }
        }

        //vertical
        for(int i=0;i<n;i++){
            if(board[i][m-1]=='O'){
                convertToY(board,i,m-1);
            }
            if(board[i][0]=='O'){
                convertToY(board,i,0);
            }
        }
        //  printBoard(board);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'){
                    board[i][j] = 'X';
                }
            }
        }
        //  printBoard(board);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='Y'){
                    board[i][j] = 'O';
                }
            }
        }
        //  printBoard(board);
        
    }
};
