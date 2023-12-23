#include <stdio.h>
#include <stdlib.h>
#include "print_array.c"

void countSort(int arr[], int arrSize);

int main()
{
    int arr[] = {9, 5, 6, 7, 3, 2, 10, 1, 4, 8};

    countSort(arr, 10);

    printArray(arr, 10);

    return 0;
}

// Maximum / largest number in an array
int maximum(int arr[], int arrSize)
{
    int i, max = 0;
    for (i = 0; i < arrSize; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void countSort(int arr[], int arrSize)
{
    int i, j = 0, max = 0;
    max = maximum(arr, arrSize);

    int *tempArr = (int *)malloc((max + 1) * sizeof(int));

    // Setting all tempArr elements = 0 ->

    for (i = 0; i < max + 1; i++)
    {
        tempArr[i] = 0;
    }

    // incrementing tempArr 0 elements
    for (i = 0; i < arrSize; i++)
    {
        tempArr[arr[i]]++;
    }

    // Copying elements back
    for (i = 0; i < max + 1; i++)
    {
        while (tempArr[i] > 0) {
            arr[j] = i;
            tempArr[i]--;
            j++;
        }
    }
    free(tempArr);
}