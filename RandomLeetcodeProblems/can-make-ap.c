#include <stdbool.h>
// https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

bool canMakeArithmeticProgression(int* arr, int arrSize) {
    qsort(arr, arrSize, sizeof(int), compare);
    int i, diff = abs(arr[1] - arr[0]);

    for (i = 1; i < arrSize; i++) {
        if (abs(arr[i] - arr[i - 1]) != diff) {
            return false;
        }
    }

    return true;
}