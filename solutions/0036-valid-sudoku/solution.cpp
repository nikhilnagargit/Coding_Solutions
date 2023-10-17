class Solution {
public:
    bool check(vector<char>& v){
      set<char> s;
      for(auto item:v){
        if(s.find(item)!=s.end()){
            return false;
        }
        s.insert(item);
      }
      return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        // check for every row;
        vector<char> v;
        for(int i=0;i<9;i++){
          for(int j=0;j<9;j++){
              if(board[i][j]!='.')
                v.push_back(board[i][j]);
          }
          if(!check(v))return false;
          v.clear();
        }
        

        // check for every column
        for(int i=0;i<9;i++){
          for(int j=0;j<9;j++){
              if(board[j][i]!='.')
            v.push_back(board[j][i]);
          }
          if(!check(v))
          return false;
            v.clear();
        }
      

        // check for every 3x3 matrix
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){

                for(int m=3*i;m<3*i+3;m++){
                    for(int n=3*j;n<3*j+3;n++){
                        if(board[m][n]!='.')
                        v.push_back(board[m][n]);
                    }
                }
                if(!check(v))
                       return false;
                         v.clear();
            }
        }
        return true;
        
    }
};
