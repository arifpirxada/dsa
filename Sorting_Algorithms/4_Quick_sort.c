#include <stdio.h>
#include "print_array.c"

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1, j = high;
    do
    {
        while (arr[i] < pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }

        if (i <= j)
        {
            swap(&arr[i], &arr[j]);
        }
    } while (i < j);

    // swap arr[low] - pivot & arr[j]

    swap(&arr[low], &arr[j]);

    return j;
}

void quickSort(int arr[], int low, int high)
{
    int partitionIndex;
    if (low < high)
    {
        partitionIndex = partition(arr, low, high);
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}

int main()
{
    int arr[] = {9, 5, 6, 7, 3, 2, 10, 1, 4, 8};

    quickSort(arr, 0, 10);

    printArray(arr, 10);

    return 0;
}