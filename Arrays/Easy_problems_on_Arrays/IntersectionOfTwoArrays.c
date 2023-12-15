// https://leetcode.com/problems/intersection-of-two-arrays/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int i, j;
    *returnSize = 0;

    int* arr = (int *)malloc(nums1Size * sizeof(int));

    for (i = 0; i < nums1Size; i++) {
        // Check for duplicates in first array
        int isDuplicate = 0;
        for (j = 0; j < *returnSize; j++) {
            if (nums1[i] == arr[j]) {
                isDuplicate = 1;
                break;
            }
        }

        if (isDuplicate) {
            continue; // Skip duplicates
        }

        for (j = 0; j < nums2Size; j++) {
            if (nums1[i] == nums2[j]) {
                arr[*returnSize] = nums1[i];
                (*returnSize)++;
                break;
            }
        }
    }

    return arr;
}