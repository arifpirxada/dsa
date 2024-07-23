// https://leetcode.com/problems/build-array-from-permutation/

int* buildArray(int* nums, int numsSize, int* returnSize) {
    int *result = (int*)malloc(numsSize * sizeof(int));

    int k = 0;
    for (int i = 0; i < numsSize; i++) {
        result[k] = nums[nums[i]];
        k++;
    }
    *returnSize = k;
    return result;
}