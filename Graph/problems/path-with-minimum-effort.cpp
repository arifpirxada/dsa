// https://leetcode.com/problems/path-with-minimum-effort

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> efforts(m, vector<int> (n, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

        pq.push({0, {0, 0}});
        efforts[0][0] = 0;

        auto isSafe = [&](int i, int j) {
            if (i >= 0 && i < m && j < n && j >=0) return true;
            return false;
        };

        vector<pair<int, int>> dirs = {
            {0, -1}, {0, 1}, {-1, 0}, {1, 0}
        };

        while (!pq.empty()) {
            auto [e, cell] = pq.top();
            pq.pop();

            auto [i, j] = cell;

            if (i == m-1 && j == n-1) return e;

            for (auto& [di, dj] : dirs) {
                int ni = i + di, nj = j + dj;
                if (isSafe(ni, nj)) {
                    int diff = abs(heights[ni][nj] - heights[i][j]);
                    int newEffort = max(e, diff);

                    if (newEffort < efforts[ni][nj]) {
                        efforts[ni][nj] = newEffort;
                        pq.push({newEffort, {ni, nj}});
                    }
                }
            }
        }

        return 0;
    }
};