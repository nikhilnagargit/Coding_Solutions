class Solution {
public:
    void printM(vector<vector<int>>& m){
        for(int i=0;i<m.size();i++){
            for(int j=0;j<m[0].size();j++){
                cout<<m[i][j]<<",";
            }
            cout<<endl;
        }
        cout<<"--------------"<<endl;
    }

    void explore(vector<vector<int>>& board,int i,int j){

        vector<pair<int,int>> mp = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}};
        int count1s = 0;
        for(auto& p :mp){
            int I = i+p.first;
            int J = j+p.second;
            if(I>=0 and I<board.size() and J>=0 and J<board[0].size() and (board[I][J]==2 or board[I][J]==1)){
                count1s ++;
            }
        }

        if(board[i][j]==1 and count1s<2){
            board[i][j] = 2;
        }
        else if(board[i][j]==1 and (count1s==2 or count1s==3)){
            board[i][j] = 1;
        }
        else if(board[i][j]==1 and count1s>3){
            board[i][j] = 2;
        }
        else if(board[i][j]==0 and count1s==3){
            board[i][j] = 3;
        }
    }

    void gameOfLife(vector<vector<int>>& board) {

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                explore(board,i,j);
            }
        }
        // printM(board);

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==2){
                    board[i][j] = 0;
                }
                else if(board[i][j]==3){
                    board[i][j] = 1;
                }
            }
        }


    }
};
