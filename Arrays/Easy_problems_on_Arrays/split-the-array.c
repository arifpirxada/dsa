// https://leetcode.com/problems/split-the-array/

int compareIntegers(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

bool isPossibleToSplit(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(nums[0]), compareIntegers);
    int times = 0;
    for (int i = 1; i < numsSize; i ++) {
        if (nums[i] == nums[i - 1]) {
            times++;
            if (times == 2) {
                return false;
            }
        } else {
            times = 0;
        }
    }
    return true;
}