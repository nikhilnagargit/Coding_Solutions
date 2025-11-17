class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int top = 0;
        int bottom = matrix.size()-1;
        int m = matrix[0].size();

        while(top<=bottom){
            int midv = top + (bottom-top)/2;
            if(matrix[midv][0]>target){
                bottom = midv-1;
            }
            else if(matrix[midv][0]<=target and matrix[midv][m-1]>=target){
                int left = 0;
                int right = m-1;
                while(left<=right){
                    int mid = left + (right-left)/2;
                    if(matrix[midv][mid]==target){
                        return true;
                    }
                    else if(matrix[midv][mid]<target){
                        left = mid+1;
                    }
                    else{
                        right = mid-1;
                    }
                }
                return false;
            }
            else {
                top = midv+1;
            }
        }
        return false;
    }
};
