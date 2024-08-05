// https://leetcode.com/problems/minimum-average-of-smallest-and-largest-elements/

class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        int n = nums.size();
        double min = DBL_MAX;
        sort(nums.begin(), nums.end());

        for (int i{}; i < n / 2; i++) {
            if ((nums[i] + nums[n - i - 1]) / 2 < min) {
                min = (nums[i] + nums[n - i - 1]) / 2.0;
            }
        }
        return min;
    }
};