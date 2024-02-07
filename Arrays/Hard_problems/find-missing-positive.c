// https://leetcode.com/problems/first-missing-positive/

int compare(const void *a, const void *b) {
    return (*(int*)a > *(int*)b) - (*(int*)a < *(int*)b);
}

int firstMissingPositive(int* nums, int numsSize) {
    int i, j = 1;
    qsort(nums, numsSize, sizeof(int), compare);

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < 1) {
            continue;
        } else if (nums[i] > j) {
            return j;
        }
        if (i + 1 != numsSize && nums[i] != nums[i + 1]) {
            j++;
        }
    }

    if (nums[numsSize - 1] < 1) {
        return 1;
    }
    return nums[numsSize - 1] + 1;
}