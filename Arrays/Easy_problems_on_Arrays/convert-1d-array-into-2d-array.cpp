// https://leetcode.com/problems/convert-1d-array-into-2d-array/

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int size = original.size();
        if (m * n != size) return {};
        vector<vector<int>> matrix(m, vector<int>(n));
        int k = 0;

        for (int i{}; i < m; i++) {
            for (int j{}; j < n; j++) {
                matrix[i][j] = original[k];
                k++;
            }
        }
        return matrix;
    }
};