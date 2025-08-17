#include <bits/stdc++.h>
using namespace std;

struct Solution {
    static const int MOD = 1000000007;

    static long long modPow(long long a, long long e) {
        long long r = 1 % MOD;
        a %= MOD;
        while (e) {
            if (e & 1) r = (r * a) % MOD;
            a = (a * a) % MOD;
            e >>= 1;
        }
        return r;
    }
    static long long modInv(long long a) {
        // MOD is prime
        return modPow((a % MOD + MOD) % MOD, MOD - 2);
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = (int)nums.size();
        if (n == 0) return 0;

        int B = max(1, (int)floor(sqrt((double)n)));

        // Partition queries by k
        unordered_map<int, vector<array<int,4>>> smallByK;
        vector<array<int,4>> large; // queries with k > B

        smallByK.reserve(B * 2);
        for (auto &q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            if (k <= B) {
                smallByK[k].push_back({l, r, k, v});
            } else {
                large.push_back({l, r, k, v});
            }
        }

        // Apply large-k queries naively (few steps per query)
        for (auto &q : large) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            long long V = ((long long)v % MOD + MOD) % MOD;
            if (V == 0) {
                for (int i = l; i <= r; i += k) nums[i] = 0;
            } else {
                for (int i = l; i <= r; i += k) {
                    nums[i] = (int)( ( (long long)nums[i] * V ) % MOD );
                }
            }
        }

        // Apply small-k queries using multiplicative difference arrays per progression
        // For each k, the sum of lengths of all residue sequences is n.
        for (auto &entry : smallByK) {
            int k = entry.first;
            auto &qs = entry.second;

            // Pre-allocate diff arrays for all residues
            // For residue r, length len_r = floor((n-1 - r)/k) + 1 if r < n, else 0
            vector<vector<long long>> diffMul(k);
            vector<vector<int>> diffZero(k); // int diff for zero-count

            vector<int> len_r(k, 0);
            for (int r = 0; r < k; ++r) {
                if (r < n) {
                    int len = 1 + ( (n - 1 - r) >= 0 ? ( (n - 1 - r) / k ) : -1 );
                    if (len < 0) len = 0;
                    len_r[r] = len;
                    // +1 for diff end marker
                    diffMul[r].assign(len + 1, 1);
                    diffZero[r].assign(len + 1, 0);
                }
            }

            // Apply all queries of this k to the appropriate residue class’ diff arrays
            for (auto &q : qs) {
                int l = q[0], r = q[1], v = q[3];
                int res = l % k;
                if (res < 0) res += k;
                if (res >= n || len_r[res] == 0) continue;

                int startIdx = (l - res) / k;
                int endIdx = (r - res) / k;
                // Clamp within this residue progression
                startIdx = max(startIdx, 0);
                endIdx   = min(endIdx, len_r[res] - 1);
                if (startIdx > endIdx) continue;

                long long V = ((long long)v % MOD + MOD) % MOD;
                if (V == 0) {
                    diffZero[res][startIdx] += 1;
                    diffZero[res][endIdx + 1] -= 1;
                } else {
                    diffMul[res][startIdx] = (diffMul[res][startIdx] * V) % MOD;
                    long long Vinv = modInv(V);
                    diffMul[res][endIdx + 1] = (diffMul[res][endIdx + 1] * Vinv) % MOD;
                }
            }

            // Materialize multiplicative prefix and apply to nums along each progression
            for (int r = 0; r < k; ++r) {
                int len = len_r[r];
                if (len == 0) continue;

                // Prefix for zero counts
                int zc = 0;
                // Prefix product for multiplicative
                long long mul = 1;

                for (int t = 0, pos = r; t < len; ++t, pos += k) {
                    zc += diffZero[r][t];
                    mul = (mul * diffMul[r][t]) % MOD;

                    if (zc > 0) {
                        nums[pos] = 0;
                    } else {
                        nums[pos] = (int)( ( (long long)nums[pos] * mul ) % MOD );
                    }
                }
            }
        }

        // Final XOR
        int ans = nums[0];
        for (int i = 1; i < n; ++i) ans ^= nums[i];
        return ans;
    }
};

