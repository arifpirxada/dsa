// https://leetcode.com/problems/pacific-atlantic-water-flow/

class Solution {
public:
    void dfsPacific(vector<vector<int>>& heights, vector<vector<pair<bool, bool>>>& canFlow, int i, int j, pair<int, int> parent) {
        if (i < 0 || j < 0 || i >= heights.size() || j >= heights[0].size() || canFlow[i][j].first == true) return;

        if (heights[parent.first][parent.second] <= heights[i][j]) {
            canFlow[i][j].first = true;

            dfsPacific(heights, canFlow, i - 1, j, {i, j});
            dfsPacific(heights, canFlow, i + 1, j, {i, j});
            dfsPacific(heights, canFlow, i, j - 1, {i, j});
            dfsPacific(heights, canFlow, i, j + 1, {i, j});
        }
    }
    void dfsAtlantic(vector<vector<int>>& heights, vector<vector<pair<bool, bool>>>& canFlow, int i, int j, pair<int, int> parent) {
        if (i < 0 || j < 0 || i >= heights.size() || j >= heights[0].size() || canFlow[i][j].second == true) return;

        if (heights[parent.first][parent.second] <= heights[i][j]) {
            canFlow[i][j].second = true;

            dfsAtlantic(heights, canFlow, i - 1, j, {i, j});
            dfsAtlantic(heights, canFlow, i + 1, j, {i, j});
            dfsAtlantic(heights, canFlow, i, j - 1, {i, j});
            dfsAtlantic(heights, canFlow, i, j + 1, {i, j});
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> result;
        vector<vector<pair<bool, bool>>> canFlow(m, vector<pair<bool, bool>> (n, {false, false})); // (pacific, Atlantic)

        // Left Column
        for (int i = 0; i < m; i++) {
            canFlow[i][0].first = true;
            dfsPacific(heights, canFlow, i, 1, {i, 0});
        }

        // Top Row
        for (int i = 1; i < n; i++) {
            canFlow[0][i].first = true;
            dfsPacific(heights, canFlow, 1, i, {0, i});
        }

        // Right Column
        for (int i = 0; i < m; i++) {
            canFlow[i][n - 1].second = true;
            dfsAtlantic(heights, canFlow, i, n - 2, {i, n - 1});
        }

        // Bottom Row
        for (int i = 0; i < n; i++) {
            canFlow[m - 1][i].second = true;
            dfsAtlantic(heights, canFlow, m - 2, i, {m - 1, i});
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (canFlow[i][j].first == true && canFlow[i][j].second == true) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};

// Better written

class Solution {
public:
    int m, n;
    const vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};

    void dfs(vector<vector<int>>& h, vector<vector<bool>>& visited, int i, int j) {
        visited[i][j] = true;
        for (auto [di, dj] : dirs) {
            int ni = i + di, nj = j + dj;
            if (ni >= 0 && ni < m && nj >= 0 && nj < n
                && !visited[ni][nj]
                && h[ni][nj] >= h[i][j]) {
                dfs(h, visited, ni, nj);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> pac(m, vector<bool>(n, false));
        vector<vector<bool>> atl(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            dfs(heights, pac, i, 0);       // left col  → Pacific
            dfs(heights, atl, i, n - 1);   // right col → Atlantic
        }
        for (int j = 0; j < n; j++) {
            dfs(heights, pac, 0, j);       // top row   → Pacific
            dfs(heights, atl, m - 1, j);   // bottom row→ Atlantic
        }

        vector<vector<int>> result;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (pac[i][j] && atl[i][j])
                    result.push_back({i, j});

        return result;
    }
};