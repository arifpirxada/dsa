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

void stackTraverse(struct stack *ptr);
void push(struct stack *ptr, int element);
int pop(struct stack *ptr);
int peek(struct stack *ptr, int index);
int peekWithZeroIndex(struct stack *ptr, int index);
int stackTop(struct stack *ptr);
int stackBottom(struct stack *ptr);

int main()
{
    // Creating a pointer for implementing "call by reference" for functions
    struct stack *newStack;
    newStack->size = 50;
    newStack->top = -1;
    newStack->arr = (int *)malloc(newStack->size * sizeof(int));

    push(newStack, 23);
    push(newStack, 43);
    push(newStack, 99);

    // pop(newStack);

    // printf("Peek: %d\n", peek(newStack, 1));
    // printf("peekWithZeroIndex: %d\n", peekWithZeroIndex(newStack, 0));

    // printf("StackTop: %d\n", stackTop(newStack));
    // printf("StackBottom: %d\n", stackBottom(newStack));

    stackTraverse(newStack);

    return 0;
}

// 1 Is Empty
int isEmpty(struct stack *ptr)
{
    // Checking if any element exists in the stack or not
    if (ptr->top < 0)
    {
        return 1;
    }
    return 0;
}

// 2 Is Full
int isFull(struct stack *ptr)
{
    // Checking if the stack is full
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}

// 3 Traverse

void stackTraverse(struct stack *ptr)
{
    if (!isEmpty(ptr))
    {
        for (int i = ptr->top; i >= 0; i--)
        {
            printf("Element: %d\n", ptr->arr[i]);
        }
    }
}

// 4 Push

void push(struct stack *ptr, int element)
{
    if (isFull(ptr))
    {
        printf("Stack overflow");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = element;
    }
}

// 5 Pop

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack underflow");
        return -1;
    }

    int elementToBeDeleted = ptr->arr[ptr->top];
    ptr->top--;

    return elementToBeDeleted;
}

// 6 Peek: getting element by index

int peek(struct stack *ptr, int index)
{
    if (index <= 0 || index > ptr->top + 1)
    {
        printf("Invalid index\n");
        return -1;
    }

    int element = ptr->arr[ptr->top - index + 1];

    return element;
}

// 7 Peek element when we start stack index from zero

int peekWithZeroIndex(struct stack *ptr, int index)
{
    if (index < 0 || index > ptr->top)
    {
        printf("Invalid index\n");
        return -1;
    }

    int element = ptr->arr[ptr->top - index];

    return element;
}

// 8 StackTop: return last element of the stack

int stackTop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack underflow!\n");
        return -1;
    }
    return ptr->arr[ptr->top];
}

// 9 StackBottom: return first element of the stack

int stackBottom(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack underflow!\n");
        return -1;
    }

    return ptr->arr[0];
}