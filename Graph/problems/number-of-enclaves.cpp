// https://leetcode.com/problems/number-of-enclaves/

class Solution {
public:
    void setWalk(pair<int, int> node, vector<vector<int>>& grid, vector<vector<bool>>& canWalk) {
        auto [i, j] = node;
        // Bound checks
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return;

        if (canWalk[i][j] == true || grid[i][j] != 1) return;
        
        canWalk[i][j] = true;

        setWalk({i - 1, j}, grid, canWalk);
        setWalk({i + 1, j}, grid, canWalk);
        setWalk({i, j - 1}, grid, canWalk);
        setWalk({i, j + 1}, grid, canWalk);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> canWalk(m, vector<bool> (n, false));
        int num = 0;

        // Left and Right column
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1)
                setWalk({i, 0}, grid, canWalk);
            if (grid[i][n - 1] == 1)
                setWalk({i, n - 1}, grid, canWalk);
        }

        // Top and Bottom row
        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 1)
                setWalk({0, j}, grid, canWalk);
            if (grid[m - 1][j] == 1)
                setWalk({m - 1, j}, grid, canWalk);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && canWalk[i][j] == false)
                    num++;
            }
        }
        
        return num;
    }
};