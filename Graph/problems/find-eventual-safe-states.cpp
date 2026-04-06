// https://leetcode.com/problems/find-eventual-safe-states


// My solution

class Solution {
public:
    bool checkSafeOrTerminal(vector<vector<int>>& g, int node, vector<bool>& vis, vector<bool>& isSafeOrTerminal) {
        vis[node] = true;
        bool iSOT = true;

        for (int neighbor : g[node]) {
            if (!vis[neighbor]) {
                if (!checkSafeOrTerminal(g, neighbor, vis, isSafeOrTerminal)) iSOT = false;
            } else if (!isSafeOrTerminal[neighbor]) {
                return false;
            }
        }

        isSafeOrTerminal[node] = iSOT;
        return iSOT;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int m = graph.size();
        vector<bool> vis(m, false);
        vector<bool> isSafeOrTerminal(m, false);
        vector<int> ans;

        for (int i = 0; i < m; i++) {
            if (vis[i]) continue;
            checkSafeOrTerminal(graph, i, vis, isSafeOrTerminal);
        }

        for (int i = 0; i < m; i++) {
            if (isSafeOrTerminal[i]) ans.push_back(i);
        }
        return ans;
    }
};

// using Cycle Detection DFS

class Solution {
public:
    bool isCycleDFS(vector<vector<int>>& g, int node, vector<bool>& vis, vector<bool>& inRecur) {
        vis[node] = true;
        inRecur[node] = true;

        for (int neighbor : g[node]) {
            if (!vis[neighbor]) {
                if (isCycleDFS(g, neighbor, vis, inRecur)) {
                    return true;
                }
            } else if (inRecur[neighbor]) {
                return true;
            }
        }

        inRecur[node] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> vis(n, false);
        vector<bool> inRecur(n, false);
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;

            isCycleDFS(graph, i, vis, inRecur);
        }

        for (int i = 0; i < n; i++) {
            if (!inRecur[i]) ans.push_back(i);
        }
        return ans;
    }
};

// Using BFS: Kahn's Algo (topological sorting)

class Solution {
public:
    vector<int> calculateIndegree(int V, vector<vector<int>>& g) {
        vector<int> inDegree(V, 0);

        for (int i = 0; i < V; i++) {
            for (int neighbor : g[i]) {
                inDegree[neighbor]++;
            }
        }
        return inDegree;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> g(n);

        for (int i = 0; i < n; i++) {
            for (int neighbor : graph[i]) {
                g[neighbor].push_back(i);
            }
        }

        vector<int> inDegree = calculateIndegree(n, g);
        vector<bool> ansBool(n, false);
        vector<int> ans;
        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int node = q.front(); q.pop();
            ansBool[node] = true;

            for (int neighbor : g[node]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) q.push(neighbor);
            }
        }

        for (int i = 0; i < n; i++) {
            if (ansBool[i]) ans.push_back(i);
        }

        return ans;
    }
};