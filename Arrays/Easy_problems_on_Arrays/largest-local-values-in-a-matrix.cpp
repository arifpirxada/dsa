// https://leetcode.com/problems/largest-local-values-in-a-matrix/

class Solution {
public:
    int findMax(vector<vector<int>>& grid, int i, int j) {
        int maxi = INT_MIN;

        for (int x = i; x < i + 3; x++) {
            for (int y = j; y < j + 3; y++) {
                maxi = max(grid[x][y], maxi);
            }
        }

        return maxi;
    }
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n - 2, vector<int>(n - 2));

        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < n - 2; j++) {
                ans[i][j] = findMax(grid, i, j);
            }
        }

        return ans;
    }
};