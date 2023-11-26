class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        vector<vector<int>> mat_copy(mat.begin(),mat.end());
        
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0;i<n;i++){
            k = k%m;
            if(i%2!=0){
                for(int j=0;j<m;j++){
                    mat[i][(j+k)%m] = mat_copy[i][j%m]; 
                }
            }
            else{
                for(int j=0;j<m;j++){
                    mat[i][j] = mat_copy[i][(j+k)%m]; 
                }  
            }
            int isrowequal = false;
            for(int k=0;k<m;k++){
                if(mat[i][k]!=mat_copy[i][k]){
                    return false;
                }
            }
        }
        return true;
    }
};
