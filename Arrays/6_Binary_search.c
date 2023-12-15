#include <stdio.h>

int binarySearch(int arr[], int arrUsedSize, int element);

int main()
{
    int arr[20] = {1, 2, 55, 93};
    printf("Element index: %d", binarySearch(arr, 4, 2));

    return 0;
}

int binarySearch(int arr[], int arrUsedSize, int element)
{
    int low = 0, mid, high = arrUsedSize - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        else if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}