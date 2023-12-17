#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

// The below functions are important for other operations like push, pop
int isEmpty(struct stack *ptr);
int isFull(struct stack *ptr);

int main()
{
    // Creating a stack data structure
    // struct Stack newStack;
    // newStack.size = 50;
    // newStack.top = -1;
    // newStack.arr = (int *)malloc(newStack.size * sizeof(int));

    // Creating a pointer for implementing "call by reference" for functions
    struct stack *newStack;
    newStack->size = 50;
    newStack->top = -1;
    newStack->arr = (int *)malloc(newStack->size * sizeof(int));

    // pushing element
    newStack->arr[0] = 13;
    newStack->top++;

    if (isEmpty(newStack)) {
        printf("Stack is empty.");
    } else {
        printf("Stack is not empty.");
    }

    return 0;
}

int isEmpty(struct stack *ptr)
{
    // Checking if any element exists in the stack or not
    if (ptr->top < 0)
    {
        return 1;
    }
    return 0;
}

int isFull(struct stack *ptr)
{
    // Checking if the stack is full
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}