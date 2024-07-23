// https://leetcode.com/problems/apply-operations-to-an-array/

int* applyOperations(int* nums, int numsSize, int* returnSize) {
    int *result = (int*)malloc(numsSize * sizeof(int));

    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            nums[i] *= 2;
            nums[i + 1] = 0;
        }
    }

    int k = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            result[k++] = nums[i];
        }
    }

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            result[k++] = nums[i];
        }
    }

    *returnSize = k;
    return result;
}