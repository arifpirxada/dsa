// https://www.geeksforgeeks.org/problems/is-it-a-tree/1

class Solution {
public:
    bool dfs(int node, vector<vector<int>> &graph, vector<bool> &vis, int parent) {
        vis[node] = true;

        for (int neighbor : graph[node]) {
            if (!vis[neighbor]) {
                if (dfs(neighbor, graph, vis, node)) {
                    return true;
                }
            } else if (neighbor != parent) {
                return true;
            }
        }

        return false;
    }

    int isTree(int n, int m, vector<vector<int>> &adj) {
        if (m != n - 1) return 0;

        vector<vector<int>> graph(n);
        for (auto &edge : adj) {
            int u = edge[0], v = edge[1];

            // Self-loop → not a tree
            if (u == v) return 0;

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<bool> vis(n, false);
        bool hasCycle = dfs(0, graph, vis, -1);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) return 0;
        }

        if (hasCycle) return 0;
        return 1;
    }
};