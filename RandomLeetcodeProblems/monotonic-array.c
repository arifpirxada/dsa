#include <stdbool.h>

// https://leetcode.com/problems/monotonic-array/

bool isMonotonic(int* nums, int numsSize) {
    int i, increasing = 1, decreasing = 1;

    for (i = 1; i < numsSize; i++) {
        if (nums[i] >= nums[i - 1]) {
            increasing++;
        }
        if (nums[i] <= nums[i - 1]) {
            decreasing++;
        }
    }

    if (increasing == numsSize || decreasing == numsSize) {
        return true;
    }

    return false;
}