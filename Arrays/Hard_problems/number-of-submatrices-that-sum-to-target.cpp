// https://leetcode.com/problems/number-of-submatrices-that-sum-to-target

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int result = 0, preSum = 0;
        int m = matrix.size(), n = matrix[0].size();

        // Prefix sum
        for (int i = 0; i < m; i++) {
            for (int j = 1; j < n; j++) {
                matrix[i][j] += matrix[i][j - 1];
            }
        }

        for (int sc = 0; sc < n; sc++) {
            for (int c = sc; c < n; c++) {
                preSum = 0;
                unordered_map<int, int> mp;
                mp[0] = 1;
                for (int r = 0; r < m; r++) {
                    int curr = matrix[r][c] - (sc > 0 ? matrix[r][sc - 1] : 0);
                    preSum += curr;

                    if (mp.find(preSum - target) != mp.end()) {
                        result += mp[preSum - target];
                    }
                    mp[preSum]++;
                }
            }
        }

        return result;
    }
};