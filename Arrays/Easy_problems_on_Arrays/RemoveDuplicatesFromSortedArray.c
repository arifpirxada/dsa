#include <stdio.h>
#include <stdlib.h>

// Link: "https://leetcode.com/problems/remove-duplicates-from-sorted-array/"

int removeDuplicates(int *nums, int numsSize);

int main()
{
    int nums[] = {1, 1, 2};
    int result = removeDuplicates(nums, 3);
    printf("Result: %d", result);

    return 0;
}

int removeDuplicates(int *nums, int numsSize)
{
    int k = 1;
    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] != nums[i - 1])
        {
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}