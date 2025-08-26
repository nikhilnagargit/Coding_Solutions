class Solution {
public:
    vector<vector<string>> ans;

    // Try to place queens row by row
    void solve(vector<string>& board, int row) {
        int n = board.size();
        if (row == n) {            // found a valid board
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (board[row][col] != '.') continue; // only place on '.'

            // Check if placing here is safe (no queens above / diagonals)
            if (!isSafe(board, row, col)) continue;

            board[row][col] = 'Q';     // place
            solve(board, row + 1);     // recurse
            board[row][col] = '.';     // undo (backtrack)
        }
    }

    bool isSafe(const vector<string>& board, int r, int c) {
        int n = board.size();

        // same column upward
        for (int i = 0; i < r; ++i)
            if (board[i][c] == 'Q') return false;

        // diag up-left
        for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; --i, --j)
            if (board[i][j] == 'Q') return false;

        // diag up-right
        for (int i = r - 1, j = c + 1; i >= 0 && j < n; --i, ++j)
            if (board[i][j] == 'Q') return false;

        return true;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        solve(board, 0);
        return ans;
    }
};

