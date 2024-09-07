// https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/

class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), low, high, mid;

        for (int i{}; i <= n; i++) {
            low = 0, high = n - 1;
            while (low <= high) {
                mid = (low + high) / 2;

                // Check if mid is the first element
                if (mid == 0) {
                    if (nums[mid] >= i && n - mid == i) {
                        return i;
                    } else {
                        break;
                    }
                }

                if (nums[mid] == i && nums[mid - 1] != i && n - mid == i) {
                    return i;
                } else if (nums[mid] > i && nums[mid - 1] < i && nums[mid - 1] != i && n - mid == i) {
                    return i;
                } else if (nums[mid] < i) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};