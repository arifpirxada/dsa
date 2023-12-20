#include <stdio.h>
#include "print_array.c"

// Selection Sort: sort array by finding minimum / smallest of elements

void selectionSort(int arr[], int arrLen);

int main()
{
    int arr[] = {9, 5, 6, 7, 3, 2, 10, 1, 4, 8};

    selectionSort(arr, 10);

    printArray(arr, 10);

    return 0;
}

void selectionSort(int arr[], int arrLen)
{
    int i = 0, j, temp, minIndex;

    while (i < arrLen - 1)
    {
        minIndex = i;
        for (j = i + 1; j < arrLen; j++)
        {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;

        i++;
    }
}