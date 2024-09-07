// https://leetcode.com/problems/spiral-matrix-ii/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n <= 0) return {};
        int element = 1;
        vector<vector<int>> ans(n, vector<int>(n));
        int left = 0, right = n - 1, top = 0, bottom = n - 1;

        while (element <= n * n) {
            for (int j = left; j <= right; ++j) {
                ans[top][j] = element++;
            }
            top++;
            if (element > n * n) break;

            for (int i = top; i <= bottom; ++i) {
                ans[i][right] = element++;
            }
            right--;
            if (element > n * n) break;

            for (int j = right; j >= left; --j) {
                ans[bottom][j] = element++;
            }
            bottom--;
            if (element > n * n) break;

            for (int i = bottom; i >= top; --i) {
                ans[i][left] = element++;
            }
            left++;
        }

        return ans;
    }
};