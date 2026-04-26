// https://leetcode.com/problems/number-of-operations-to-make-network-connected/

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1; // Not enough cables

        list<int> g[n];

        for (vector conn : connections) {
            g[conn[0]].push_back(conn[1]);
            g[conn[1]].push_back(conn[0]);
        }
        int mini = -1;
        vector<bool> vis(n, false);
        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            
            mini++;
            q.push(i);
            vis[i] = true;

            while (!q.empty()) {
                int node = q.front(); q.pop();
                for (int neighbor : g[node]) {
                    if (!vis[neighbor]) {
                        q.push(neighbor);
                        vis[neighbor] = true;
                    }
                }
            }
        }

        return mini;
    }
};