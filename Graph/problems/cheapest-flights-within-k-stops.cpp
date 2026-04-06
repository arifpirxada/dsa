// https://leetcode.com/problems/cheapest-flights-within-k-stops

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> g(n);

        for (auto &f : flights) {
            g[f[0]].push_back({f[1], f[2]});
        }

        // dist[node][stops remaining]
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));

        priority_queue<
            tuple<int,int,int>, 
            vector<tuple<int,int,int>>, 
            greater<>
        > pq;

        pq.push({0, src, k + 1});
        dist[src][k + 1] = 0;

        while (!pq.empty()) {
            auto [cost, node, stops] = pq.top();
            pq.pop();

            if (node == dst) return cost;

            if (stops == 0) continue;

            for (auto &[nei, wt] : g[node]) {
                int newCost = cost + wt;

                if (newCost < dist[nei][stops - 1]) {
                    dist[nei][stops - 1] = newCost;
                    pq.push({newCost, nei, stops - 1});
                }
            }
        }

        return -1;
    }
};