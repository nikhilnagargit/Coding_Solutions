class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto dist2 = [&](const vector<int>& p){
            return 1LL*p[0]*p[0] + 1LL*p[1]*p[1];
        };
        if (k <= 0) return {};
        if (k >= (int)points.size()) return points;

        nth_element(points.begin(), points.begin() + (k - 1), points.end(),
                    [&](const vector<int>& a, const vector<int>& b){
                        long long da = dist2(a), db = dist2(b);
                        if (da != db) return da < db;
                        // optional tie-breaker to keep it deterministic:
                        if (a[0] != b[0]) return a[0] < b[0];
                        return a[1] < b[1];
                    });
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};

