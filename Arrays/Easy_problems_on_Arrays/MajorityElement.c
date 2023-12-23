// https://leetcode.com/problems/majority-element/

int compareIntegers(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int majorityElement(int* nums, int numsSize) {

    qsort(nums, numsSize, sizeof(nums[0]), compareIntegers);
    return nums[numsSize / 2];
}