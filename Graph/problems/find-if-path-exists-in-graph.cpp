// https://leetcode.com/problems/find-if-path-exists-in-graph/

class Solution {
public:
    bool checkPath(int node, list<int> g[], int dest, vector<bool>& vis) {
        if (node == dest) return true; 
        vis[node] = true;

        for (int neighbor : g[node]) {
            if (!vis[neighbor]) {
                if (checkPath(neighbor, g, dest, vis)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool> vis(n, false);
        list<int> g[n];

        for (vector<int> edge : edges) {
            int u = edge[0], v = edge[1];
            
            g[u].push_back(v);
            g[v].push_back(u);
        }

        return checkPath(source, g, destination, vis);
    }
};