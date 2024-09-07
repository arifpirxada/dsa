// https://leetcode.com/problems/find-the-highest-altitude/

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi = 0;

        for (int i{}; i < gain.size() - 1; i++) {
            gain[i + 1] += gain[i];
        }

        for (int num: gain) {
            maxi = max(maxi, num);
        }

        return maxi;
    }
};