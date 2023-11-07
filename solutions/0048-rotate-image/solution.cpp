class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // transpose the martix;
        int n = matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n-i-1;j++){
                swap(matrix[i][j],matrix[n-1-j][n-i-1]);
            }
        }

        // flip vertically
        for(int i=0;i<n/2;i++){
            for(int j=0;j<n;j++){
                swap(matrix[i][j],matrix[n-1-i][j]);
            }
        }

    }
};
