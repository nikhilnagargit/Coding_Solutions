class Solution:
    def minInsertions(self, s: str) -> int:
        def longestPalindromeSubseq(s: str) -> int:
            n = len(s)
            @lru_cache(maxsize=None)
            def solve(i: int, j: int) -> int:
                if i > j:
                    return 0
                if i == j:
                    return 1

                if s[i] == s[j]:
                    return 2 + solve(i + 1, j - 1)

                return max(solve(i + 1, j), solve(i, j - 1))
            return solve(0, n - 1)
        l = longestPalindromeSubseq(s)
        return len(s)-l
