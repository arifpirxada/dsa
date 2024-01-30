// https://leetcode.com/problems/rotate-array/

void rotate(int* nums, int numsSize, int k) {
    int i, j = 0;
    int* arr = (int*)malloc(numsSize * sizeof(int));
    k = k % numsSize;
    if (k <= numsSize) {


        for (i = 0; i < numsSize - k; i++) {
            arr[i] = nums[i];
        }

        for (i = 0; i < k; i++) {
            nums[i] = nums[numsSize - k + i];
        }

        for (i = k; i < numsSize; i++) {
            nums[i] = arr[j];
            j++;
        }
    } else {
        for (i = 0; i < numsSize; i++) {
            arr[i] = nums[i];
        }
        for (i = 0; i < numsSize; i++) {
            nums[i] = arr[numsSize - (i + 1)];
        }
    }
    free(arr);
}