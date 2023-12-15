// https://leetcode.com/problems/move-zeroes/

void moveZeroes(int* nums, int numsSize) {
    int i, j;
    for (i = numsSize - 1; i >= 0; i--) {
        if  (nums[i] == 0) {
            for (j = i; j < numsSize; j++) {
                if (j == numsSize - 1) {
                    nums[j] = 0;
                    break;
                }
                nums[j] = nums[j + 1];
            }
        }
    }
}