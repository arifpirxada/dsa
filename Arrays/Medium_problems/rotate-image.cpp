// https://leetcode.com/problems/rotate-image/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> temp(matrix.size(), vector<int>(matrix[0].size()));

        for (int i{}; i < matrix.size(); i++) {
            for (int j{}; j < matrix[0].size(); j++) {
                temp[j][matrix[0].size() - i - 1] = matrix[i][j];
            }
        }

        for(int i{}; i < matrix.size(); i++) {
            for (int j{}; j < matrix[0].size(); j++) {
                matrix[i][j] = temp[i][j];
            }
        }
    }
};