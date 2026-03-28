// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold

class Solution {
public:
    bool isDivisor(vector<int>& nums, int threshold, int divisor) {
        int sum = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            int result = (nums[i] + divisor - 1) / divisor;
            sum += result;

            if (sum > threshold) return false;
        }
        return true;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int smallestDivisor = high, mid;

        while (low <= high) {
            mid = low + (high - low) / 2;

            if (isDivisor(nums, threshold, mid)) {
                smallestDivisor = min(smallestDivisor, mid);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return smallestDivisor;
    }
};