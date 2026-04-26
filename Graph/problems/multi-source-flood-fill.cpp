// https://leetcode.com/problems/multi-source-flood-fill/

class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        queue<pair<pair<int, int>, int>> q; // {{i, j}, c}
        vector<vector<int>> grid(n, vector<int> (m, 0));

        auto isSafe = [&](int i, int j) {
            if (i >= 0 && i < n && j >= 0 && j < m) return true;
            return false;
        };

        for (vector s : sources) {
            q.push({{s[0], s[1]}, s[2]});
            grid[s[0]][s[1]] = s[2];
        }

        vector<pair<int, int>> dirs = {
            {0, -1}, {0, 1}, {-1, 0}, {1, 0}
        };

        while (!q.empty()) {
            int sz = q.size();
            unordered_map<int, int> mp;

            for (int k = 0; k < sz; k++) {
                auto [node, color] = q.front(); q.pop();
                auto [i, j] = node;
    
                for (auto [di, dj] : dirs) {
                    int ni = i + di, nj = j + dj;
    
                    if (isSafe(ni, nj) && grid[ni][nj] == 0) {
                        int key = ni * m + nj;
                        mp[key] = max(mp[key], color);
                    }
                }
            }

            for (auto [key, color] : mp) {
                int i = key / m;
                int j = key % m;
                grid[i][j] = color;
                q.push({{i, j}, color});
            }
            
        }
        return grid;
    }
};