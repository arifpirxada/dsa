// https://leetcode.com/problems/network-delay-time

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int ans = 0;
        vector<int> dist(n + 1, INT_MAX);
        list<pair<int, int>> g[n + 1];
        // {weight, u}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Create graph

        for (vector<int> edge : times) {
            int u = edge[0], v = edge[1], wt = edge[2];
            g[u].push_back({v, wt});
        }

        pq.push({0, k});
        dist[k] = 0;

        while (!pq.empty()) {
            auto [wt, u] = pq.top();
            pq.pop();

            if (dist[u] < wt) continue;

            for (auto [v, wt] : g[u]) {
                if (dist[u] != INT_MAX && dist[v] > dist[u] + wt) {
                    dist[v] = dist[u] + wt;
                    pq.push({dist[v], v});
                }
            }
        }

        for (int i = 1; i <= n; i++ ) {
            if (dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};