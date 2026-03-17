// https://leetcode.com/problems/score-after-flipping-matrix/

// Solves some test cases:

class Solution {
public:
    int convertToInt(vector<int>& binary) {
        int num = 0;

        for (int i = 0; i < binary.size(); i++) {
            num = num * 2 + binary[i];
        }

        return num;
    }

    int getOnes(vector<vector<int>>& grid, int j) {
        int count = 0;

        for (int i = 0; i < grid.size(); i++) {
            if (grid[i][j] == 1) count++;
        }

        return count;
    }

    int matrixScore(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 0) {
                for (int j = 0; j < n; j++) {
                    grid[i][j] ^= 1;
                }
            }
        }

        for (int j = 1; j < n; j++) {
            int ones = getOnes(grid, j);

            if (ones < m / 2) {
                for (int i = 0; i < m; i++) {
                    grid[i][j] ^= 1;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            ans += convertToInt(grid[i]);
        }

        return ans;
    }
};

// Read optimized solution:

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        for (int j = 0; j < n; j++) {

            int ones = 0;

            for (int i = 0; i < m; i++) {

                int bit = grid[i][j];

                if (grid[i][0] == 0)
                    bit ^= 1;

                if (bit == 1)
                    ones++;
            }

            int best = max(ones, m - ones);

            ans += best * (1 << (n - j - 1));
        }

        return ans;
    }
};