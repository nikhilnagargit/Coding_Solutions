class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1){
            return s;
        }
        int length = s.size();
        // make a matrix
        int rows = numRows+1;
        int columns = 500;
        vector<vector<char>> matrix(rows, vector<char> (columns, '0'));
        // start filling matrix;
        int k=0;
        int i=-1;
        int j=0;
        while(k<length){
            // go down
            while(k<length and i<numRows-1){
                i++;
                 matrix[i][j] = s[k];
     
                k++;
            }
            // go diagonally up
            while(k<length and i>0){
                i--;
                j++;
         
                matrix[i][j] = s[k];
                k++;
            }
        }
        // traverse the matrix and make new string
        string new_s = "";
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(matrix[i][j]!='0'){
                    new_s+=matrix[i][j];
                }
            }
        }
        return new_s;
    }
};
