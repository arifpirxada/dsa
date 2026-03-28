class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j, int n, int m) {
        if (i < 0 || i >= n || j < 0 || j >= m || visited[i][j] || grid[i][j] == '0') return;

        visited[i][j] = true;

        dfs(grid, visited, i + 1, j, n, m);
        dfs(grid, visited, i - 1, j, n, m);
        dfs(grid, visited, i, j + 1, n, m);
        dfs(grid, visited, i, j - 1, n, m);
    }
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    dfs(grid, visited, i, j, n, m);
                    islands++;
                }
            }
        }

        return islands;
    }
};

// without visited array, reducing space usage


class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j, int n, int m) {
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == '0') return;

        grid[i][j] = '0'; // mark visited

        dfs(grid, i + 1, j, n, m);
        dfs(grid, i - 1, j, n, m);
        dfs(grid, i, j + 1, n, m);
        dfs(grid, i, j - 1, n, m);
    }
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j, n, m);
                    islands++;
                }
            }
        }

        return islands;
    }
};