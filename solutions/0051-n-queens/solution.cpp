class Solution {
public:
    bool collision(vector<string>& board,int r, int col,int n){
        //check upper board 
        int col1 = col-1;
        int col2 = col+1;
        int row = r-1;
        while(row>=0){
            if(col1>=0 and board[row][col1]=='Q'){
                return true;
            }
            if(col2<n and board[row][col2]=='Q'){
                return true;
            } 
            if(board[row][col]=='Q'){
                return true;
            }
            col1--;
            col2++;
            row--;
        }
        return false;
    }

    void solve(vector<string>&board, vector<vector<string>>&ans,int row,int n){
        //we want to put a queen in current row , then move to next row and fill there
        if(row==n){
            ans.push_back(board);
            return;
        }
        //check if putting at block i , will it cross any exisiting queen
        for(int i=0;i<n;i++){
            //check if we can put the queen and move to next
            if(!collision(board,row,i,n)){
                board[row][i] = 'Q';
                solve(board,ans,row+1,n);
            }
            // revert the board
            board[row][i]='.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> v;
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            string s="";
            for(int j=0;j<n;j++){
                s+='.';
            }
            v.push_back(s);
        }
        solve(v,ans,0,n);
        return ans;
    }
};
