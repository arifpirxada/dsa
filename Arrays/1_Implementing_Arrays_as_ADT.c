#include <stdio.h>
#include <stdlib.h>

// Implementation of Array as an "Abstract Data Type"
// Creating array Data Structure

struct arr
{
    int size;
    int usedSize;
    int *ptr;
};

// Function to reserve memory dynamically
void createArray(struct arr *instance, int totalSize, int usedSize);

void setArrayValues(struct arr *instance);

void showArray(struct arr *instance);

int main()
{
    // Instance of array Data Structure
    struct arr nums;

    createArray(&nums, 20, 10);
    setArrayValues(&nums);
    showArray(&nums);

    return 0;
}

void createArray(struct arr *instance, int totalSize, int usedSize)
{
    instance->size = totalSize;
    instance->usedSize = usedSize;
    instance->ptr = (int *)malloc(totalSize * sizeof(int));
}

void setArrayValues(struct arr *instance)
{
    int i, val;
    for (i = 0; i < instance->usedSize; i++) {
        printf("\nEnter element %d: ", i);
        scanf("%d", &val);
        (instance->ptr)[i] = val;
    }
}

void showArray(struct arr *instance)
{
    int i;
    for (i = 0; i < instance->usedSize; i++) {
        printf("%d\n", (instance->ptr)[i]);
    }
}