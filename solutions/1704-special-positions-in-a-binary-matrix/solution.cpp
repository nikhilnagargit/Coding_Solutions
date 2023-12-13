class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int count=0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1){
                    bool checkrow = true;
                    bool checkcol = true;
                    for(int m = 0;m<mat.size();m++){
                        if(m!=i and mat[m][j]==1){
                            checkrow = false;
                            break;
                        }
                    }
                    for(int n=0;n<mat[0].size();n++){
                        if(n!=j and mat[i][n]==1){
                            checkcol = false;
                            break;
                        }
                    }
                    if(checkrow and checkcol){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
