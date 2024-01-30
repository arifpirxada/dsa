// https://leetcode.com/problems/set-mismatch/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    int i;
    int *ans = (int *)malloc(2 * sizeof(int));
    *returnSize = 2;

    qsort(nums, numsSize, sizeof(int), compare);

    int expectedSum = numsSize * (numsSize + 1) / 2;
    int actualSum = 0;

    for (i = 0; i < numsSize; i++) {
        actualSum += nums[i];
        if (i > 0 && nums[i] == nums[i - 1]) {
            ans[0] = nums[i];
        }
    }

    ans[1] = expectedSum - (actualSum - ans[0]);

    return ans;
}