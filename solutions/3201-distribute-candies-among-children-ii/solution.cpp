class Solution {
public:
     using ll = long long;
    long long distributeCandies(int n, int limit) {
        long long ans = 0;
        for (int i = 0; i <= min(limit, n); ++i) {
            const auto candies = n - i;
            if (candies > limit * 2) {
                continue;
            }
            if (candies > limit) {
                ans += (limit * 2 - candies + 1);
            } else {
                ans += candies + 1;
            }
        }
        return ans;
    }
};
