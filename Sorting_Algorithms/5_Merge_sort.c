#include <stdio.h>
#include <stdlib.h>
#include "print_array.c"

// Sorts an array whose two parts are "sorted" seperated by an index "mid" through merging
void merge(int arr[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0;
    int *tempArr = (int *)malloc((high - low + 1) * sizeof(int));

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            tempArr[k] = arr[i];
            i++;
        }
        else
        {
            tempArr[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid)
    {
        tempArr[k] = arr[i];
        i++;
        k++;
    }

    while (j <= high)
    {
        tempArr[k] = arr[j];
        j++;
        k++;
    }

    for (i = low, k = 0; i <= high; i++, k++)
    {
        arr[i] = tempArr[k];
    }
    free(tempArr);
}

// Sorts array with merging ->
void mergeSort(int arr[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main()
{
    // Merge two sorted arrays into one array ->
    // int array1[] = {1, 2, 4, 8, 10}; // sorted array
    // int array2[] = {3, 5, 6, 7, 9};  // sorted array
    // int array3[10];

    // mergeSortedArrays(array1, 5, array2, 5, array3);
    // printArray(array3, 10);

    // Merge function usage ->
    // int arr[] = {3, 5, 6, 7, 9, 1, 2, 4, 8, 10}; // sorted from 0 - 4 & 5 - 9

    // merge(arr, 0, 4, 10);
    // printArray(arr, 10);

    // mergeSort usage here ->

    int arr[] = {9, 5, 6, 7, 3, 2, 10, 1, 4, 8};
    mergeSort(arr, 0, 9);
    printArray(arr, 10);

    return 0;
}

// Merges two sorted arrays into one sorted array (This function is for concept)
// void mergeSortedArrays(int arr1[], int arr1Size, int arr2[], int arr2Size, int arr3[])
// {
//     int i, j, k;
//     i = j = k = 0;

//     while (i < arr1Size && j < arr2Size)
//     {
//         if (arr1[i] < arr2[j])
//         {
//             arr3[k] = arr1[i];
//             i++;
//             k++;
//         }
//         else
//         {
//             arr3[k] = arr2[j];
//             j++;
//             k++;
//         }
//     }

//     while (i < arr1Size)
//     {
//         arr3[k] = arr1[i];
//         i++;
//         k++;
//     }

//     while (j < arr1Size)
//     {
//         arr3[k] = arr2[j];
//         j++;
//         k++;
//     }
// }