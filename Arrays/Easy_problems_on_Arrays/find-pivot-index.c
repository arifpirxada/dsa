// https://leetcode.com/problems/find-pivot-index/

// - Find total sum and name it rightSum.
// - Set leftSum = 0.
// - Traverse the array
// - while traversing subtract the current element from rightSum.
// - And check if leftSum is equal to rightSum, if yes return current index.
// - At the end of loop add current element to leftSum and subtract leftSum from rightSum

int pivotIndex(int* nums, int numsSize) {
    // Find total sum (rightSum):
    int rightSum = 0, leftSum = 0;

    for (int i = 0; i < numsSize; i++) {
        rightSum += nums[i];
    }

    // Check rightSum == leftSum
    for (int i = 0; i < numsSize; i++) {
        if (leftSum == (rightSum - nums[i])) {
            return i;
        }
        rightSum -= nums[i];
        leftSum += nums[i];
    }

    return -1;
}