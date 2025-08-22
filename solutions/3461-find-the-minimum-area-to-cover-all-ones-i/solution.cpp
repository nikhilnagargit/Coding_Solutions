#include <vector>
using namespace std;

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        const int n = (int)grid.size();
        const int m = (int)grid[0].size();

        // Find first and last rows that contain a 1 (skip empty rows fast)
        int top = 0;
        while (top < n && !rowHasOne(grid[top])) ++top;

        int bottom = n - 1;
        while (bottom >= 0 && !rowHasOne(grid[bottom])) --bottom;

        // No 1s at all
        if (top > bottom) return 0;

        int left = m, right = -1;

        // Only scan rows that could contain the rectangle
        for (int i = top; i <= bottom; ++i) {
            const auto& row = grid[i];

            // Find first 1 from the left
            int l = 0;
            while (l < m && row[l] == 0) ++l;

            // Find first 1 from the right
            int r = m - 1;
            while (r >= 0 && row[r] == 0) --r;

            if (l < m) { // row has at least one 1
                if (l < left) left = l;
                if (r > right) right = r;
            }
        }

        // Area of bounding rectangle
        return (right - left + 1) * (bottom - top + 1);
    }

private:
    static inline bool rowHasOne(const vector<int>& row) {
        // Fast check if any cell is 1; early exit on first hit
        for (int v : row) if (v) return true;
        return false;
    }
};

