#include <stdio.h>

// Link: "https://leetcode.com/problems/merge-sorted-array/"

void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n);

int main()
{
    int nums1[] = {1, 2, 3, 0, 0, 0}, nums2[] = {2, 5, 6}, m = 3, n = 3, i;
    merge(nums1, 6, m, nums2, 3, n);

    for (i = 0; i < 6; i++)
    {
        printf("Element: %d\n", nums1[i]);
    }

    return 0;
}

void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n)
{
    int i, j = m, temp;
    for (i = 0; i < n; i++)
    {
        nums1[j] = nums2[i];
        j++;
    }
    for (i = 0; i < n + m; i++)
    {
        for (j = 0; j < n + m; j++)
        {
            if (i == j)
            {
                continue;
            }
            if (nums1[i] < nums1[j])
            {
                temp = nums1[i];
                nums1[i] = nums1[j];
                nums1[j] = temp;
            }
        }
    }
}