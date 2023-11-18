class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int topRow = 0;
        int bottomRow = n-1;
        while(topRow<=bottomRow){
            int midRow = topRow + (bottomRow-topRow)/2;
            if(target>= matrix[midRow][0] and target<=matrix[midRow][m-1]){
                // start another binary search
                int left = 0;
                int right = m-1;
                while(left<=right){
                    int mid = left+ (right-left)/2;
                    if(matrix[midRow][mid]==target){
                        return true;
                    }
                    else if(matrix[midRow][mid]>target){
                        right = mid-1;
                    }
                    else{
                        left = mid+1;
                    }
                }
                return false;
            }
            else if(target>matrix[midRow][m-1]){
                topRow = midRow+1;
            }
            else{
                bottomRow = midRow-1;
            }

        }
    return false;

    }
};
