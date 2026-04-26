// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int MOD = 1e9 + 7;
        list<pair<int, int>> g[n]; // {u, time}

        for (vector road : roads) {
            g[road[0]].push_back({road[1], road[2]});
            g[road[1]].push_back({road[0], road[2]});
        }

        vector<long long> time(n, LLONG_MAX);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq; // {time, u}
        vector<long long> ways(n, 0);

        pq.push({0, 0});
        time[0] = 0;
        ways[0] = 1;

        while (!pq.empty()) {
            auto [t, u] = pq.top();
            pq.pop();

            if (t > time[u]) continue;

            for (auto [v, nt] : g[u]) {
                long long jointTime = nt + t;
                if (jointTime < time[v]) {
                    time[v] = jointTime;
                    ways[v] = ways[u];
                    pq.push({time[v], v});
                } else if (jointTime == time[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};