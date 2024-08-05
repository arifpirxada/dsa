// https://leetcode.com/problems/number-of-employees-who-met-the-target/

class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int ans = 0, n = hours.size();
        for (int i = 0; i < n; i++) {
            if (hours[i] >= target) {
                ans++;
            }
        }
        return ans;
    }
};