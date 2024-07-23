// https://leetcode.com/problems/find-target-indices-after-sorting-array/

int compareIntegers(const void *a, const void *b) {
    int intA = *(int *)a;
    int intB = *(int *)b;
    return (intA - intB);
}

int* targetIndices(int* nums, int numsSize, int target, int* returnSize) {
    qsort(nums, numsSize, sizeof(nums[0]), compareIntegers);

    int k = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == target) {
            nums[k++] = i;
        }
    }

    *returnSize = k;

    return nums;
}