class Solution {
public:


    bool isValidSudoku(vector<vector<char>>& board) {
        int m  = 9;
        int n  = 9;
        for(int i=0;i<n;i++){
            unordered_set<char> rows;
            unordered_set<char> cols;
            for(int j=0;j<m;j++){
                if(board[i][j]!='.' and rows.count(board[i][j])>0){
                    // cout<<i<<j;
                    return false;
                }
                else{
                    rows.insert(board[i][j]);
                }
                if(board[j][i]!='.' and cols.count(board[j][i])>0){
                    //   cout<<"2";
                    return false;
                }
                else{
                    cols.insert(board[j][i]);
                }
            }
            rows.clear();
            cols.clear();
        }

        // 3x3 boxes valid
        for(int a=0;a<3;a++){
            for(int b=0;b<3;b++){
                unordered_set<char> s;
                for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++){
                        if(board[i+a*3][j+b*3]!='.' and s.count(board[i+a*3][j+b*3])>0){
                            //   cout<<"3";
                            return false;
                        }
                        else{
                            s.insert(board[i+a*3][j+b*3]);
                        }
                    }
                }
            }
        }

        return true;

    }
};
