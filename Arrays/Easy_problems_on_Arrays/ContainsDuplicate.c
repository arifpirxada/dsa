#include <stdbool.h>

// Link: "https://leetcode.com/problems/contains-duplicate/"

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
bool containsDuplicate(int* nums, int numsSize) {
    int i, j, temp;
    qsort(nums, numsSize, sizeof(int), compare);
    for (i = 1; i < numsSize; i++) {
      if (nums[i] == nums[i - 1]) {
          return true;
      }
    }
    return false;
}