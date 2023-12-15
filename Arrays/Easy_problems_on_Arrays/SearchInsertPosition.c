#include <stdio.h>
#include <stdlib.h>

// Link: "https://leetcode.com/problems/search-insert-position/"

int searchInsert(int *nums, int numsSize, int target);

int main()
{
    int nums[] = {1, 3, 5, 6}, target = 5;
    int result = searchInsert(nums, 4, target);
    printf("Result: %d", result);

    return 0;
}

int searchInsert(int *nums, int numsSize, int target)
{
    int index;

    if (numsSize == 1)
    {
        if (nums[0] > target)
        {
            return 0;
        }
        else if (nums[0] < target)
        {
            return 1;
        }
    }

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == target)
        {
            index = i;
            return index;
        }
        else if (i == numsSize - 1)
        {
            index = i + 1;
            return index;
        }
        else if (nums[i] < target && nums[i + 1] > target)
        {
            index = i + 1;
            return index;
        }
        else if (nums[0] > target)
        {
            index = 0;
            return index;
        }
    }
    return 0;
}