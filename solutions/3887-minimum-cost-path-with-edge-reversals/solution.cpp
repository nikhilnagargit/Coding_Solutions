class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        using ll = long long;
        vector<vector<pair<int,int>>> g(n);
        // For each edge u->v with cost w, also allow v->u with cost 2*w
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            g[u].push_back({v, w});
            g[v].push_back({u, 2*w});
        }

        const ll INF = LLONG_MAX/4;
        vector<ll> dist(n, INF);
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;

        dist[0] = 0;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d != dist[u]) continue;          // stale
            if (u == n-1) return (int)d;         // early exit
            for (auto [v, w] : g[u]) {
                ll nd = d + w;
                if (nd < dist[v]) {
                    dist[v] = nd;
                    pq.push({nd, v});
                }
            }
        }
        return -1;
    }
};
