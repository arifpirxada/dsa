// leetcode.com/problems/concatenation-of-array/

int* getConcatenation(int* nums, int numsSize, int* returnSize) {
    int *ans = (int*)malloc((2 * numsSize) * sizeof(int));
    int i;
    for (i = 0; i < 2 * numsSize; i++) {
        if (i >= numsSize) {
            ans[i] = nums[i - numsSize];
        } else {
            ans[i] = nums[i];
        }
    }
    *returnSize = i;
    return ans;
}