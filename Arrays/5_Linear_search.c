#include <stdio.h>

int linearSearch(int arr[], int arrUsedSize, int element);

int main()
{
    int arr[20] = {1, 2, 55, 23};
    printf("Element index: %d", linearSearch(arr, 4, 55));

    return 0;
}

int linearSearch(int arr[], int arrUsedSize, int element)
{
    for (int i = 0; i < arrUsedSize; i++)
    {
        if (arr[i] == element) {
            return i;
        }
    }

    return -1;
}