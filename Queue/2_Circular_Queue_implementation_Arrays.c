#include <stdio.h>
#include <stdlib.h>

struct circularQueue // Change
{
    int size;
    int frondIndex;
    int backIndex;
    int *arr;
};

void traverseQueue(struct circularQueue *ptr);
int isEmpty(struct circularQueue *ptr);
int isFull(struct circularQueue *ptr);
void enqueue(struct circularQueue *ptr, int element);
int dequeue(struct circularQueue *ptr);

int main()
{
    struct circularQueue *numsQueue;
    numsQueue->size = 5;
    // Change: frontIndex = 0 & backIndex = 0 So isFull condition will work properly
    numsQueue->frondIndex = 0;
    numsQueue->backIndex = 0;
    numsQueue->arr = (int *)malloc(numsQueue->size * sizeof(int));

    // Insert element
    enqueue(numsQueue, 35);
    enqueue(numsQueue, 44);
    enqueue(numsQueue, 8);
    enqueue(numsQueue, 12);

    // dequeue(numsQueue);
    // dequeue(numsQueue);
    // dequeue(numsQueue);
    // dequeue(numsQueue);

    enqueue(numsQueue, 89);

    traverseQueue(numsQueue);

    return 0;
}

int isEmpty(struct circularQueue *ptr)
{
    if (ptr->backIndex == ptr->frondIndex)
    {
        return 1;
    }
    return 0;
}

int isFull(struct circularQueue *ptr)
{
    if ((ptr->backIndex + 1) % ptr->size == ptr->frondIndex) // Change
    {
        return 1;
    }
    return 0;
}

void traverseQueue(struct circularQueue *ptr)
{
    int i = (ptr->frondIndex + 1) % ptr->size; // Change
    while (i != (ptr->backIndex + 1) % ptr->size) // Change
    {
        printf("Element: %d\n", ptr->arr[i]);
        i = (i + 1) % ptr->size; // Change
    }
}

void enqueue(struct circularQueue *ptr, int element)
{
    if (isFull(ptr))
    {
        printf("Queue overflow!\n");
    }
    else
    {
        ptr->backIndex = (ptr->backIndex + 1) % ptr->size; // Change
        ptr->arr[ptr->backIndex] = element;
    }
}

int dequeue(struct circularQueue *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Queue underflow!\n");
        return -1;
    }

    ptr->frondIndex = (ptr->frondIndex + 1) % ptr->size; // Change

    return ptr->arr[ptr->frondIndex];
}