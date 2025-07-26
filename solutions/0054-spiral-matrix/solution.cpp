class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()) return {};

        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;

        vector<int> ans;

        while(top <= bottom && left <= right) {
            // Left to right
            for(int j = left; j <= right; ++j)
                ans.push_back(matrix[top][j]);
            top++;

            // Top to bottom
            for(int i = top; i <= bottom; ++i)
                ans.push_back(matrix[i][right]);
            right--;

            // Right to left
            if(top <= bottom) {
                for(int j = right; j >= left; --j)
                    ans.push_back(matrix[bottom][j]);
                bottom--;
            }

            // Bottom to top
            if(left <= right) {
                for(int i = bottom; i >= top; --i)
                    ans.push_back(matrix[i][left]);
                left++;
            }
        }

        return ans;
    }
};

