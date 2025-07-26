class Solution {

public:

    void setZeroes(vector<vector<int>>& matrix) {
        // rowwise
        int isFirstRowZero = 0;
        int isFirstColZero = 0;

        for(int i=0;i<matrix.size();i++){
            if(matrix[i][0]==0){
                isFirstColZero = 1;
                break;
            }
        }


        for(int j=0;j<matrix[0].size();j++){
            if(matrix[0][j]==0){
                isFirstRowZero = 1;
                break;
            }
        }



        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
    


        for(int i=1;i<matrix.size();i++){
            if(matrix[i][0]==0){
                // make row zero
                for(int j=0;j<matrix[0].size();j++){
                    matrix[i][j]=0;
                }
            }
        }


        for(int j=1;j<matrix[0].size();j++){
            if(matrix[0][j]==0){
                // make col zero
                for(int i=0;i<matrix.size();i++){
                    matrix[i][j]=0;
                }
            }
        }
        


        if(isFirstColZero){
            for(int i=0;i<matrix.size();i++){
                matrix[i][0] = 0;
            }
        }

        if(isFirstRowZero){
            for(int j=0;j<matrix[0].size();j++){
                matrix[0][j]=0;
            }
        }
  
        
    }
};
