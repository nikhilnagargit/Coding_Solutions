class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        vector<int>vect(matrix[0].size(),0);
        for(int i=0;i<matrix[0].size();i++){
            int maxvalue = 0;
            for(int j=0;j<matrix.size();j++){
                maxvalue = max(maxvalue,matrix[j][i]);
            }
            vect[i] = maxvalue;
        }
        
        
        vector<vector<int>> ans(matrix.size(),vector<int>(matrix[0].size(),0));
        
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==-1){
                    ans[i][j] = vect[j];
                }
                else{
                    ans[i][j]= matrix[i][j];
                }
            }
        }
        return ans;
        
    }
};
