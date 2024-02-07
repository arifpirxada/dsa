// https://leetcode.com/problems/maximum-subarray/

int maxSubArray(int* nums, int numsSize) {
    int i, maxSum = nums[0], curSum = 0;

    for (i = 0; i < numsSize; i++) {
        curSum += nums[i];

        if (curSum > maxSum) {
            maxSum = curSum;
        }

        if (curSum < 0) {
            curSum = 0;
        }
    }

    return maxSum;
}