#include <stdlib.h>
// https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int** divideArray(int* nums, int numsSize, int k, int* returnSize, int** returnColumnSizes) {
    int i, j = 0;
    int **ans = (int**)malloc(numsSize * sizeof(int*));

    *returnColumnSizes = (int*)malloc(numsSize * sizeof(int));

    for (i = 0; i < numsSize; i++) {
        ans[i] = (int *)malloc(3 * sizeof(int));
        (*returnColumnSizes)[i] = 3;
    }

    qsort(nums, numsSize, sizeof(int), compare);

    for (i = 0; i < numsSize - 2; i += 3) {
        if (nums[i + 2] - nums[i] > k) {
            *returnSize = 0;
            return NULL;
        }
        
        ans[j][0] = nums[i];
        ans[j][1] = nums[i + 1];
        ans[j][2] = nums[i + 2];
        j++;
    }

    *returnSize = j;

    return ans;
}