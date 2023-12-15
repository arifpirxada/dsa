#include <stdio.h>
#include "2_Array_traversal.c"

int insertAtIndex(int arr[], int arrSize, int arrUsedSize, int element, int index);

int main()
{
    int arr[20] = {1, 2, 55, 23};
    insertAtIndex(arr, 20, 4, 10, 1);
    traversal(arr, 5);

    return 0;
}

int insertAtIndex(int arr[], int arrSize, int arrUsedSize, int element, int index)
{
    // Checking for array capacity
    if (arrUsedSize >= arrSize || index < 0)
    {
        return -1;
    }
    
    for (int i = arrUsedSize; i > index; i--)
    {
        arr[i] = arr[i - 1];
    }
    
    arr[index] = element;
    return 1;
}