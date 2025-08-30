class Solution {
public:
    int minCut(string s) {
        int n = (int)s.size();
        // dp[i][j] = whether s[i..j] is a palindrome
        vector<vector<char>> dp(n, vector<char>(n, 0));
        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                if (len == 1) dp[i][j] = 1;
                else if (len == 2) dp[i][j] = (s[i] == s[j]);
                else dp[i][j] = (s[i] == s[j]) && dp[i+1][j-1];
            }
        }

        // pp[i] = minimum number of palindromic parts for s[0..i]
        // (answer will be pp[n-1] - 1 cuts)
        const int INF = 1e9;
        vector<int> pp(n, INF);

        for (int i = 0; i < n; ++i) {
            if (dp[0][i]) {
                pp[i] = 1;                 // whole prefix is a palindrome -> 0 cuts
            } else {
                for (int j = 1; j <= i; ++j) {
                    if (dp[j][i] && pp[j-1] != INF) {
                        pp[i] = min(pp[i], pp[j-1] + 1);
                    }
                }
            }
        }
        return pp[n-1] - 1;
    }
};

