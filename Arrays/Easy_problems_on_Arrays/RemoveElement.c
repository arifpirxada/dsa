#include <stdio.h>
#include <stdlib.h>

// Link: "https://leetcode.com/problems/remove-element/"

int removeElement(int *nums, int numsSize, int val);

int main()
{
    int nums[] = {3, 2, 2, 3}, val = 3;
    int result = removeElement(nums, 4, val);
    printf("Result: %d", result);

    return 0;
}

int removeElement(int *nums, int numsSize, int val)
{
    int k = numsSize, j = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] != val)
        {
            nums[j] = nums[i];
            j++;
        }
        else if (nums[i] == val)
        {
            k--;
        }
    }
    return k;
}