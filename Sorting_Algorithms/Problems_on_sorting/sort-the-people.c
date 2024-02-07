#include <stdlib.h>
#include <limits.h>
// https://leetcode.com/problems/sort-the-people/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** sortPeople(char** names, int namesSize, int* heights, int heightsSize, int* returnSize) {
    int i = 0, j, k = 0, tallest, tallestIndex;
    char **ans = (char **)malloc(namesSize * sizeof(char*));

    while (i < namesSize) {
        tallest = INT_MIN;
        for (j = 0; j < namesSize; j++) {
            if (heights[j] > tallest) {
                tallest = heights[j];
                tallestIndex = j;
            }
        }

        ans[k] = (char*)malloc((strlen(names[tallestIndex]) + 1) * sizeof(char));
        strcpy(ans[k], names[tallestIndex]);
        heights[tallestIndex] = -1;

        k++;
        i++;
    }

    *returnSize = k;
    return ans;
}