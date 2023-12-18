#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    // Front index is used to keep tract of first element - usefull for deletion operation time complexity "O(1)" else "O(n)"
    int frondIndex;
    int backIndex;
    int *arr;
};

void traverseQueue(struct Queue *ptr);
int isEmpty(struct Queue *ptr);
int isFull(struct Queue *ptr);
void enqueue(struct Queue *ptr, int element);
int dequeue(struct Queue *ptr);

int main()
{
    struct Queue *numsQueue;
    numsQueue->size = 50;
    numsQueue->frondIndex = -1;
    numsQueue->backIndex = -1;
    numsQueue->arr = (int *)malloc(numsQueue->size * sizeof(int));

    // Insert element
    enqueue(numsQueue, 35);
    enqueue(numsQueue, 44);
    enqueue(numsQueue, 8);
    enqueue(numsQueue, 12);
    enqueue(numsQueue, 89);

    int removedElement = dequeue(numsQueue);
    traverseQueue(numsQueue);
    printf("Removed element: %d\n", removedElement);

    return 0;
}

int isEmpty(struct Queue *ptr)
{
    if (ptr->backIndex == ptr->frondIndex)
    {
        return 1;
    }
    return 0;
}

int isFull(struct Queue *ptr)
{
    if (ptr->backIndex == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}

void traverseQueue(struct Queue *ptr)
{
    int i = ptr->frondIndex + 1;
    while (i != ptr->backIndex + 1)
    {
        printf("Element: %d\n", ptr->arr[i]);
        i++;
    }
}

void enqueue(struct Queue *ptr, int element)
{
    if (isFull(ptr))
    {
        printf("Queue overflow!");
    }
    else
    {
        ptr->backIndex++;
        ptr->arr[ptr->backIndex] = element;
    }
}

int dequeue(struct Queue *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Queue underflow!");
        return -1;
    }

    ptr->frondIndex++;

    return ptr->arr[ptr->frondIndex];
}