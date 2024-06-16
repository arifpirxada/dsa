// https://leetcode.com/problems/check-if-it-is-a-straight-line/

class Solution {
public:
    double calculate(vector<int> p1, vector<int> p2) {
        if (p1[0] == p2[0]) {
            return INT_MAX;
        }
        return ((p1[1] - p2[1]) * 1.0) / ((p1[0] - p2[0]) * 1.0);
    }
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if (coordinates.size() <= 2) {
            return true;
        }

        double slope = calculate(coordinates[0], coordinates[1]);

        for (int i = 2; i < coordinates.size(); i++) {
            if (calculate(coordinates[0], coordinates[i]) != slope) {
                return false;
            }
        }
        return true;
    }
};