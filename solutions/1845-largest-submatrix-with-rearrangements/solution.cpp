class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int max_area = 0;

        for(int i=1;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
              if(matrix[i][j]==1){
                  matrix[i][j] = matrix[i-1][j]+1;
              }
            }
        }

        for(int i=0;i<matrix.size();i++){
            vector<int>v(matrix[i].begin(),matrix[i].end());
            sort(v.begin(),v.end(),greater<int>());
            for(int j=0;j<v.size();j++){
                max_area = max(max_area,v[j]*(j+1));
            }
        }
        return max_area;
    }
};
