class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int m = y+k;
        int n = x+k;
        for(int i=x;i<(x+(k)/2);i++){
            for(int j=y;j<m;j++){
                swap(grid[i][j],grid[n-1-(i-x)][j]);
            }
        }
        return grid;
    }
};
