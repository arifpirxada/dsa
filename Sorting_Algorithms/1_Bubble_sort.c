#include <stdio.h>
#include "print_array.c"

void bubbleSort(int arr[], int arrLen);
void adaptiveBubbleSort(int arr[], int arrLen);

int main()
{
    int arr[] = {9, 5, 6, 7, 3, 2, 10, 1, 4, 8};

    bubbleSort(arr, 10);
    // adaptiveBubbleSort(arr, 10);

    printArray(arr, 10);

    return 0;
}

void bubbleSort(int arr[], int arrLen)
{
    int i = 0, j, temp;

    while (i < arrLen - 1)
    {
        for (j = 0; j < arrLen - 1 - i ; j++)
        {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        i++;
    }
}

void adaptiveBubbleSort(int arr[], int arrLen) {
    int i = 0, j, temp, sorted = 1;

    while (i < arrLen)
    {
        for (j = 0; j < arrLen - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                sorted = 0;
            }
        }
        if (sorted) {
            printf("The array is already sorted!\n");
            break;
        }
        i++;
    }
}