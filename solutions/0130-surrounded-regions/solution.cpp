class Solution {
public:

   bool is_valid(vector<vector<char>>& board,int i,int j){
       int m = board.size()-1;
       int n = board[0].size()-1;
       if(i>=0 and i<=m and j>=0 and j<=n){
           return true;
       }
       return false;
   }
    void convert(vector<vector<char>>& board,char source,char target){
        int m = board.size();
        int n = board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==source){
                    board[i][j]=target;
                }
            }
        }
    }

   void make_T(vector<vector<char>>& board,int i,int j){
       if(!is_valid(board,i,j)){
           return;
       }
       if(board[i][j]=='O'){
           board[i][j] = 'T';
           make_T(board,i+1,j);
           make_T(board,i,j+1);
           make_T(board,i-1,j);
           make_T(board,i,j-1);
       }
    }
 

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        

        for(int j=0;j<n;j++){
            // top boundary  i=0;
            make_T(board,0,j);
            // bottom boundary  i=m-1;
            make_T(board,m-1,j);
        }

        for(int i=1;i<m-1;i++){
            // right boundary j=n-1;
            make_T(board,i,n-1);
            // left boundary j=0;
            make_T(board,i,0);
        }
        convert(board,'O','X');
        convert(board,'T','O');

    }
};
