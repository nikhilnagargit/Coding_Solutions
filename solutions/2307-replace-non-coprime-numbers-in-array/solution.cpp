#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<long long> st;  // keep in 64-bit while merging

        for (int v : nums) {
            long long x = v;
            // keep merging with stack top while gcd > 1
            while (!st.empty()) {
                long long g = std::gcd(st.back(), x);
                if (g == 1) break;
                // compute lcm(st.back(), x) as (st.back()/g) * x
                // use __int128 to avoid intermediate overflow
                __int128 t = (__int128)(st.back() / g) * x;
                x = (long long)t;         // assuming constraints keep it in 64-bit
                st.pop_back();
            }
            st.push_back(x);
        }

        // convert back to int if required by the platform
        vector<int> ans;
        ans.reserve(st.size());
        for (auto v : st) ans.push_back((int)v);
        return ans;
    }
};

