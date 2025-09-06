class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        dp[0][0] = grid[0][0];

        // {time, i, j}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> min_heap;
        min_heap.push({dp[0][0], 0, 0});

        vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!min_heap.empty()) {
            auto curr = min_heap.top(); min_heap.pop();
            int time = curr[0], i = curr[1], j = curr[2];

            if (i == n - 1 && j == n - 1) return time;

            for (auto [di, dj] : dirs) {
                int ni = i + di, nj = j + dj;
                if (0 <= ni && ni < n && 0 <= nj && nj < n) {
                    int nt = max(time, grid[ni][nj]);
                    if (nt < dp[ni][nj]) {
                        dp[ni][nj] = nt;
                        min_heap.push({nt, ni, nj});
                    }
                }
            }
        }
        return dp[n-1][n-1];
    }
};

