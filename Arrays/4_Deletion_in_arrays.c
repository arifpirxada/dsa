#include <stdio.h>
#include "2_Array_traversal.c"

int deleteAtIndex(int arr[], int arrUsedSize, int index);

int main()
{
    int arr[20] = {1, 2, 55, 23};
    deleteAtIndex(arr, 4, 1);
    traversal(arr, 3);

    return 0;
}

int deleteAtIndex(int arr[], int arrUsedSize, int index)
{
    if (index < 0)
    {
        return -1;
    }

    for (int i = index; i < arrUsedSize; i++)
    {
        arr[i] = arr[i + 1];
    }

    return 1;
}