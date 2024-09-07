// https://leetcode.com/problems/matrix-diagonal-sum/

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        int j = 0;
        int n = mat.size();

        for (int i{}; i < n && j < n; i++) {
            sum += mat[i][j];
            if (j != n - j - 1 ) {
                sum += mat[i][n - j - 1];
            }
            j++;
        }
        return sum;
    }
};