#include <limits.h>
// https://leetcode.com/problems/relative-sort-array/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize) {
    int i, j, k = 0;
    int *ans = (int*)malloc(arr1Size * sizeof(int));

    for (i = 0; i < arr2Size; i++) {
        for (j = 0; j < arr1Size; j++) {
            if (arr2[i] == arr1[j]) {
                arr1[j] = INT_MAX;
                ans[k] = arr2[i];
                k++;
            }
        }
    }

    int min;
    int minIndex = -1;

    for (i = k; i < arr1Size; i++) {
        min = INT_MAX;
        minIndex = -1;
        for (j = 0; j < arr1Size; j++) {
            if (arr1[j] < min) {
                min = arr1[j];
                minIndex = j;
            }
        }
        ans[k] = min;
        k++;
        arr1[minIndex] = INT_MAX;
    }

    *returnSize = k;
    return ans;
}