// https://leetcode.com/problems/kth-largest-element-in-an-array/

// todo: Solve it without sorting

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int findKthLargest(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), compare);  
    return nums[numsSize - k];
}