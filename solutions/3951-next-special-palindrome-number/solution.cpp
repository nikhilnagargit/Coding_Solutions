#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long specialPalindrome(long long n) {
        static vector<long long> specials = generateSpecial();
        auto it = upper_bound(specials.begin(), specials.end(), n);
        if (it != specials.end()) return *it;
        return -1;  // or handle "none found" as you prefer
    }

private:
    static vector<long long> generateSpecial() {
        vector<long long> res;
        vector<int> evenDigits, oddDigits;
        for (int k = 1; k <= 9; ++k) {
            (k % 2 == 0 ? evenDigits : oddDigits).push_back(k);
        }
        int E = evenDigits.size();
        for (int maskE = 0; maskE < (1 << E); ++maskE) {
            vector<int> base;
            int sumBase = 0;
            for (int i = 0; i < E; ++i) {
                if (maskE & (1 << i)) {
                    base.push_back(evenDigits[i]);
                    sumBase += evenDigits[i];
                }
            }
            if (sumBase > 16) continue;
            processSet(base, 0, res);
            for (int od : oddDigits) {
                if (sumBase + od > 16) continue;
                base.push_back(od);
                processSet(base, od, res);
                base.pop_back();
            }
        }
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }

    static void processSet(const vector<int>& S, int oddDigit, vector<long long>& res) {
        // build half-string
        string half;
        for (int d : S) half += string(d / 2, char('0' + d));
        string center = oddDigit ? string(1, char('0' + oddDigit)) : "";

        // if both half and center are empty, no digits at all—skip
        if (half.empty() && center.empty()) return;

        sort(half.begin(), half.end());
        do {
            if (!half.empty() && half[0] == '0') continue;
            string pal = half + center + string(half.rbegin(), half.rend());
            // pal is guaranteed non-empty now
            res.push_back(stoll(pal));
        } while (next_permutation(half.begin(), half.end()));
    }
};

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     Solution sol;
//     long long n;
//     if (!(cin >> n)) return 0;
//     cout << sol.specialPalindrome(n) << "\n";
//     return 0;
// }

