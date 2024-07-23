// https://leetcode.com/problems/check-if-array-is-good/

int compareIntegers(const void *a, const void *b) {
    int intA = *(int *)a;
    int intB = *(int *)b;
    return (intA - intB);
}

bool isGood(int* nums, int numsSize){
    if (numsSize < 2) {
        return false;
    }

    qsort(nums, numsSize, sizeof(int), compareIntegers);

    if (nums[numsSize - 1] != nums[numsSize - 2] || nums[0] != 1) {
        return false;
    }

    for (int i = 1; i < numsSize - 1; i++) {
        if (nums[i] - 1 != i) {
            return false;
        }
    }

    return true;
}