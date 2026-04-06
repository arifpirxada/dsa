// https://leetcode.com/problems/01-matrix

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> result(m, vector<int> (n, -1));
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    result[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            if (i > 0 && result[i - 1][j] == -1) {
                result[i - 1][j] = result[i][j] + 1;
                q.push({i - 1, j});
            }

            if (i < m - 1 && result[i + 1][j] == -1) {
                result[i + 1][j] = result[i][j] + 1;
                q.push({i + 1, j});
            }

            if (j > 0 && result[i][j - 1] == -1) {
                result[i][j - 1] = result[i][j] + 1;
                q.push({i, j - 1});
            }

            if (j < n - 1 && result[i][j + 1] == -1) {
                result[i][j + 1] = result[i][j] + 1;
                q.push({i, j + 1});
            }
        }

        return result;
    }
};