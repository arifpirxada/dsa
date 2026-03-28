// https://leetcode.com/problems/rotting-oranges/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int, int>, int>> q;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int mx_min = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    pair <int, int> node = {i, j};
                    pair <pair<int, int>, int> p = {node, 0};
                    q.push(p);
                    visited[i][j] = true;
                }
            }
        }

        while(!q.empty()) {
            pair p = q.front();
            pair node = p.first;
            int i = node.first;
            int j = node.second;
            int time = p.second;
            q.pop();

            mx_min = max(mx_min, time);

            if (i > 0 && !visited[i - 1][j] && grid[i - 1][j] != 0) {
                pair <int, int> newPair = {i - 1, j};
                pair <pair<int, int>, int> newP = {newPair, time + 1};
                q.push(newP);
                visited[i - 1][j] = true;
            }

            if (i < m - 1 && !visited[i + 1][j] && grid[i + 1][j] != 0 ) {
                pair <int, int> newPair = {i + 1, j};
                pair <pair<int, int>, int> newP = {newPair, time + 1};
                q.push(newP);
                visited[i + 1][j] = true;
            }

            if (j > 0 && !visited[i][j - 1] && grid[i][j - 1] != 0) {
                pair <int, int> newPair = {i, j - 1};
                pair <pair<int, int>, int> newP = {newPair, time + 1};
                q.push(newP);
                visited[i][j - 1] = true;
            }

            if (j < n - 1 && !visited[i][j + 1] && grid[i][j + 1] != 0) {
                pair <int, int> newPair = {i, j + 1};
                pair <pair<int, int>, int> newP = {newPair, time + 1};
                q.push(newP);
                visited[i][j + 1] = true;
            }

        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    return -1;
                }
            }
        }

        return mx_min;
    }
};