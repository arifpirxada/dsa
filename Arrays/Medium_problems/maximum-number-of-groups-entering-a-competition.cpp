// https://leetcode.com/problems/maximum-number-of-groups-entering-a-competition/

class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();
        int groups = 0;
        int students = 0;

        while (students + groups + 1 <= n) {
            groups++;
            students += groups;
        }

        return groups;
    }
};