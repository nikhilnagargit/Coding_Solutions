class Solution {
public:
    void nextstate(vector<vector<int>>& board,int i,int j){
        vector<int>I{0,0,1,-1,1,1,-1,-1};
        vector<int>J{1,-1,0,0,1,-1,1,-1};
        int countof1=0;
        for(int k=0;k<I.size();k++){
            int first = i+I[k];
            int second = j+J[k];
            if(0<=first and first<board.size() and 0<=second and second<board[0].size()){
                if(board[first][second]==1 or board[first][second]==3){
                    countof1++;
                }
            }
        }
        if((board[i][j]==1 or board[i][j]==3) and countof1<2){
            board[i][j]=3;
        }
        else if((board[i][j]==1 or board[i][j]==3) and countof1<=3){
            board[i][j]=1;
        }
        else if((board[i][j]==1 or board[i][j]==3) and countof1>3){
            board[i][j]=3;
        }
        else if((board[i][j]==0 or board[i][j]==2) and countof1==3){
            board[i][j]=2;
        }
        else{
        
        }
    }
    void gameOfLife(vector<vector<int>>& board) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                nextstate(board,i,j);
            }
        }

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==2){
                    board[i][j]=1;
                }
                else if(board[i][j]==3){
                    board[i][j]=0;
                }
            }
        }
    }
};
