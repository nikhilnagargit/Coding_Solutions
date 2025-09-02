
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& edges, int n, int k) {
        // adjacency list: u -> [(v, w)]
        vector<vector<pair<int,int>>> adj(n + 1);
        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        const int INF = INT_MAX / 2;
        vector<int> dist(n + 1, INF);
        dist[k] = 0;

        // min-heap of (dist, node)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue; // skip stale entries

            for (auto [v, w] : adj[u]) {
                int newcost = d + w;
                if (newcost < dist[v]) {
                    dist[v] = newcost;
                    pq.push({newcost, v});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == INF) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};

