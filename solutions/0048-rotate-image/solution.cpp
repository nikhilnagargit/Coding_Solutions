class Solution {
public:


    void rotate(vector<vector<int>>& matrix) {
        int m = matrix[0].size();
        int n = matrix.size();

        // transpose 
        for (int i=0;i<n;i++){
            for(int j=i;j<m;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        // printM(matrix);

        // flip
        for (int j=0;j<=(m-1)/2;j++){
            for(int i=0;i<n;i++){
                swap(matrix[i][j],matrix[i][m-j-1]);
            }
        }

        // printM(matrix);

    }
};
