// https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int maxWidth = INT_MIN, n = points.size();
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        for (int i = 1; i < n; i++) {
            if (points[i][0] - points[i - 1][0] > maxWidth) {
                maxWidth = points[i][0] - points[i - 1][0];
            }
        }

        return maxWidth;
    }
};