// https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* replaceElements(int* arr, int arrSize, int* returnSize) {
    int i, j = 0, bigElem = 0, bigIndex = 0;

    int *ans = (int *)malloc(arrSize * sizeof(int));

    while (j < arrSize) {
        if (bigIndex <= j) {
            bigElem = 0;
            for (i = j + 1; i < arrSize; i++) {
                if (arr[i] > bigElem) {
                    bigElem = arr[i];
                    bigIndex = i;
                }
            }
        }
        ans[j] = bigElem;
        j++;
    }
    *returnSize = j;
    ans[*returnSize - 1] = -1;

    return ans;
}