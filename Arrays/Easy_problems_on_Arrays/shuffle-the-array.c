// https://leetcode.com/problems/shuffle-the-array/

int* shuffle(int* nums, int numsSize, int n, int* returnSize){
    int *result = (int*)malloc(numsSize * sizeof(int));
    int x = 0;
    int y = n;

    for (int i = 0; i < n; i++) {
        result[x] = nums[i];
        result[x + 1] = nums[y++];
        x += 2;
    }
    *returnSize = numsSize;
    return result;
}