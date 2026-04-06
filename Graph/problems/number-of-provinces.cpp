// https://leetcode.com/problems/number-of-provinces/

class Solution {
public:
    void dfs(vector<vector<int>>& isCon, int node, int n, vector<bool>& vis) {
        vis[node] = true;

        for (int neighbor = 0; neighbor < n; neighbor++) {
            if (isCon[node][neighbor] == 1 && !vis[neighbor]) {
                dfs(isCon, neighbor, n, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n, false);

        int pro = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(isConnected, i, n, vis);
                pro++;
            }
        }
        return pro;
    }
};

// BFS version

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n, false);
        int pro = 0;

        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            pro++;

            q.push(i);
            vis[i] = true;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int neighbor = 0; neighbor < n; neighbor++) {
                    if (isConnected[node][neighbor] == 1 && !vis[neighbor]) {
                        q.push(neighbor);
                        vis[neighbor] = true;
                    }
                }
            }
        }

        return pro;        
    }
};