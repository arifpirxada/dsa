// https://leetcode.com/problems/minimum-time-difference/

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size(), min, hours = 0, ans = INT_MAX;
        vector<int> minutes(n, 0);

        for (int i = 0; i < n; i++) {
            hours = timePoints[i][0] - '0';
            hours = (hours * 10) + timePoints[i][1] - '0';
            min = ((timePoints[i][3] - '0') * 10) + (timePoints[i][4] - '0');
            minutes[i] = (hours * 60) + min;
            cout << minutes[i] << " ";
        }
        sort(minutes.begin(), minutes.end());
        for (int i = 1; i < n; i++) {
            if (minutes[i] - minutes[i - 1] < ans) {
                ans = minutes[i] - minutes[i - 1];
            }
            if ((minutes[i - 1] + 1440) - minutes[i] < ans) {
                ans = (minutes[i - 1] + 1440) - minutes[i];
            }
        }
        if ((minutes[0] + 1440) - minutes[n - 1] < ans) {
            ans = (minutes[0] + 1440) - minutes[n - 1];
        }
        return ans;
    }
};