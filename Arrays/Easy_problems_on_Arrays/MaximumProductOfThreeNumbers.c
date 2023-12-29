// https://leetcode.com/problems/maximum-product-of-three-numbers/

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int maximumProduct(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);

    if ((nums[numsSize - 1] * nums[numsSize - 2] * nums[numsSize - 3]) > (nums[0] * nums[1] * nums[numsSize - 1])) {
        return (nums[numsSize - 1] * nums[numsSize - 2] * nums[numsSize - 3]);
    }

    return (nums[0] * nums[1] * nums[numsSize - 1]);
}