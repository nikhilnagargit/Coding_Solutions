class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int top = 0;
        int bottom = matrix.size()-1;
        int m = matrix[0].size();

        while(top<=bottom){
            int mid = top + (bottom-top)/2;
            // check if found
            if(matrix[mid][0]==target) return true;
            else if(matrix[mid][0]>target) bottom = mid-1;
            else{
                if(matrix[mid][m-1]==target) return true;
                else if(matrix[mid][m-1]<target){
                    top = mid+1;
                }
                else{
                    // search in that row
                    for(int j=1;j<m-1;j++){
                        if(matrix[mid][j]==target)return true;
                    }
                    return false;
                }
            }
        }
        return false;
    }
};
