// https://leetcode.com/problems/shortest-path-in-binary-matrix/

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // Base cases: start or end is blocked
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        // {distance, {row, col}}
        queue<pair<int, pair<int,int>>> q;
        q.push({1, {0, 0}});
        grid[0][0] = 1; // mark visited

        vector<pair<int,int>> dirs = {
            {0,1},{0,-1},{1,0},{-1,0},
            {1,1},{1,-1},{-1,1},{-1,-1}
        };

        while (!q.empty()) {
            auto [dist, node] = q.front();
            auto [i, j] = node;
            q.pop();

            if (i == n-1 && j == n-1) return dist; // reached destination

            for (auto [di, dj] : dirs) {
                int ni = i + di, nj = j + dj;
                if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] == 0) {
                    q.push({dist + 1, {ni, nj}});
                    grid[ni][nj] = 1; // mark visited immediately
                }
            }
        }

        return -1;
    }
};

// Using Dikstra's Algo

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // Base cases: start or end is blocked
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        vector<vector<int>> dist(n, vector<int> (n, INT_MAX));

        // {distance, {row, col}}
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        pq.push({1, {0, 0}});
        grid[0][0] = 1; // mark visited
        dist[0][0] = 1;

        vector<pair<int,int>> dirs = {
            {0,1},{0,-1},{1,0},{-1,0},
            {1,1},{1,-1},{-1,1},{-1,-1}
        };

        auto isSafe = [&](int i, int j) {
            if (i >= 0 && i < n && j >= 0 && j < n) return true;
            return false;
        };

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            auto [i, j] = node;
            pq.pop();

            for (auto [di, dj] : dirs) {
                int ni = i + di, nj = j + dj;
                if (isSafe(ni, nj) && grid[ni][nj] == 0) {
                    pq.push({d + 1, {ni, nj}});
                    grid[ni][nj] = 1;
                    dist[ni][nj] = d + 1;
                }
            }
        }
        return dist[n-1][n-1] == INT_MAX ? -1 : dist[n-1][n-1];
    }
};