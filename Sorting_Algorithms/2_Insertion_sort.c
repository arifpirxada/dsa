#include <stdio.h>
#include "print_array.c"

void insertionSort(int arr[], int arrSize);

int main()
{
    int arr[] = {9, 5, 6, 7, 3, 2, 10, 1, 4, 8};

    insertionSort(arr, 10);

    printArray(arr, 10);

    return 0;
}

void insertionSort(int arr[], int arrSize)
{
    int i, j, temp;
    for (i = 1; i < arrSize; i++)
    {

        // 1st Way
        for (j = i; j > 0; j--)
        {

            if (arr[j] < arr[j - 1])
            {
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
            else
            {
                break;
            }
        }

        // 2nd Way

        // temp = arr[i];
        // j = i - 1;

        // while (j >= 0 && arr[j] > temp)
        // {
        //     arr[j + 1] = arr[j];
        //     j--;
        // }
        // arr[j + 1] = temp;
    }
}