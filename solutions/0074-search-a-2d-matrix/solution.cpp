class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // find row from first column
        int top = 0;
        int bottom = matrix.size()-1;
        while(top<bottom){
            int mid = top+(bottom-top)/2;
            if(matrix[mid][0]==target){
                return true;
            }
            else if(matrix[mid][0]>target){
                bottom = mid-1;
            }
            else if(matrix[mid][0]<target and matrix[mid][matrix[0].size()-1]>=target) {
                bottom = mid;
                top = mid;
            }
            else{
                top = mid+1;
            }
        }
        cout<<top;
        int left = 0;
        int right = matrix[0].size()-1;
        while(left<=right){
             int mid = left+(right-left)/2;
            if(matrix[top][mid]==target){
                return true;
            }
            else if(matrix[top][mid]>target){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        
        return false;
    }
};
