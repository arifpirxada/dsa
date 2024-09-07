// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0, low, high, mid;

        for (int i{}; i < grid.size(); i++) {
            low = 0, high = grid[0].size() - 1;
            while (low <= high) {
                mid = (low + high) / 2;
                if (grid[i][mid] < 0) {
                    if (mid != 0 && grid[i][mid - 1] < 0) {
                        high = mid - 1;
                    } else {
                        count += grid[i].size() - mid;
                        break;
                    }
                } else {
                    low = mid + 1;
                }
            }
        }

        return count;
    }
};