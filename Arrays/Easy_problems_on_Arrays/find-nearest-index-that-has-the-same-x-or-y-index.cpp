// https://leetcode.com/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate/submissions/1337021488/

class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int smallestDistance = INT_MAX;
        int index = -1;

        for (int i{}; i < points.size(); i++) {
            // Check if points is valid
            if (points[i][0] == x || points[i][1] == y) {
                if (smallestDistance > abs(x - points[i][0]) + abs(y - points[i][1])) {
                    smallestDistance = abs(x - points[i][0]) + abs(y - points[i][1]);
                    index = i;
                }
            }
        }

        return index;
    }
};