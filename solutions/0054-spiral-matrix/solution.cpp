class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int left = 0;
        int right = matrix[0].size()-1;
        int top = 0;
        int bottom = matrix.size()-1;

        while(left<=right and top<=bottom){
        // left to right
        for(int j=left;j<=right;j++){
            ans.push_back(matrix[left][j]);
        }
        top++;
    
        // top to  bottom
        for(int i=top;i<=bottom && left<=right;i++){
            ans.push_back(matrix[i][right]);
        }
        right--;
   

        // right to left
        for(int j=right;j>=left && top<=bottom;j--){
            ans.push_back(matrix[bottom][j]);
        }
        bottom--;
 
        // bottom to top
     
         for(int i=bottom;i>=top&&left<=right;i--){
             ans.push_back(matrix[i][left]);
         }
         left++;
         
    }
    return ans;
    }
};
