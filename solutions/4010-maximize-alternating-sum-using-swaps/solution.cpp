struct DSU {
    vector<int> p, r;
    DSU(int n): p(n), r(n,0) { iota(p.begin(), p.end(), 0); }
    int find(int x){ return p[x]==x ? x : p[x]=find(p[x]); }
    void unite(int a, int b){
        a = find(a); b = find(b);
        if (a == b) return;
        if (r[a] < r[b]) swap(a, b);
        p[b] = a;
        if (r[a] == r[b]) r[a]++;
    }
};

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums, vector<vector<int>>& swaps) {
        int n = (int)nums.size();
        DSU dsu(n);

        // Treat swaps as 0-based indices
        for (auto &e : swaps) {
            if ((int)e.size() < 2) continue;
            int a = e[0], b = e[1];
            if (0 <= a && a < n && 0 <= b && b < n) dsu.unite(a, b);
        }

        unordered_map<int, vector<int>> comp_vals;
        unordered_map<int, int> comp_even_slots;

        for (int i = 0; i < n; ++i) {
            int r = dsu.find(i);
            comp_vals[r].push_back(nums[i]);
            if ((i & 1) == 0) comp_even_slots[r]++;  // even index => "+" slot
        }

        long long ans = 0;
        for (auto &kv : comp_vals) {
            auto &vals = kv.second;
            sort(vals.begin(), vals.end(), greater<int>());
            int k = comp_even_slots[kv.first];  // number of "+" slots
            long long sum_topk = 0, total = 0;
            for (int i = 0; i < (int)vals.size(); ++i) {
                total += vals[i];
                if (i < k) sum_topk += vals[i];
            }
            ans += 2 * sum_topk - total;  // contribution per component
        }

        return ans;
    }
};
