class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = (int)nums.size();
        if (n < 2) return -1;

        // inc[i]: nums[0..i] strictly increasing
        vector<char> inc(n, 0), dec(n, 0);
        inc[0] = 1;
        for (int i = 1; i < n; ++i) {
            inc[i] = inc[i-1] && (nums[i-1] < nums[i]);
        }

        // dec[i]: nums[i..n-1] strictly decreasing
        dec[n-1] = 1;
        for (int i = n - 2; i >= 0; --i) {
            dec[i] = dec[i+1] && (nums[i] > nums[i+1]);
        }

        long long total = 0;
        for (int x : nums) total += x;

        long long pref = 0, ans = LLONG_MAX;
        bool found = false;

        for (int k = 0; k <= n - 2; ++k) {
            pref += nums[k]; // sum of nums[0..k]
            if (inc[k] && dec[k+1]) {
                found = true;
                long long diff = llabs(2*pref - total);
                if (diff < ans) ans = diff;
            }
        }

        return found ? ans : -1;
    }
};

