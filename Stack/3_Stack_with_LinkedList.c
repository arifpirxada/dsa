#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traverseLinkedList(struct Node *ptr);
int isEmpty(struct Node *ptr);
int isFull(struct Node *ptr);
struct Node *push(struct Node *top, int element);
int pop(struct Node **top);
int peek(struct Node *top, int index);
int stackTop(struct Node *top);
int stackBottom(struct Node *top);

int main()
{
    struct Node *top = NULL;
    top = push(top, 29);
    top = push(top, 50);
    top = push(top, 39);

    // printf("Popped Element: %d\n", pop(&top));
    // printf("Peeked Element: %d\n", peek(top, 3));
    // printf("StackTop: %d\n", stackTop(top));
    // printf("StackBottom: %d\n", stackBottom(top));

    traverseLinkedList(top);

    return 0;
}

void traverseLinkedList(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// 1 isEmpty
int isEmpty(struct Node *ptr)
{
    if (ptr == NULL)
    {
        return 1;
    }
    return 0;
}

// 2 isFull
int isFull(struct Node *ptr)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL)
    {
        return 1;
    }
    return 0;
}

// 3 Push
struct Node *push(struct Node *top, int element)
{
    if (isFull(top))
    {
        printf("Stack overflow!\n");
        return top;
    }
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = element;
    newNode->next = top;
    top = newNode;

    return top;
}

// 4 Pop
int pop(struct Node **top)
{
    if (isEmpty(*top))
    {
        printf("Stack underflow!\n");
        return -1;
    }
    struct Node *nodeToBeDeleted = *top;
    *top = (*top)->next;
    int deletedNodeData = nodeToBeDeleted->data;

    free(nodeToBeDeleted);

    return deletedNodeData;
}

// 5 Peek
int peek(struct Node *top, int index) {
    if (index <= 0) {
        printf("Invalid index\n");
        return -1;
    }
    for (int i = 1; i < index && top != NULL; i++) {
        top = top->next;
    }
    if (top == NULL) {
        printf("Index does not exist!\n");
        return -1;
    }
    return top->data;
}

int stackTop(struct Node *top) {
    if (top == NULL) {
        printf("Stack underflow!\n");
        return -1;
    }
    return top->data;
}

int stackBottom (struct Node *top) {
    struct Node *ptr = top;
    if (top == NULL) {
        printf("Stack underflow!\n");
        return -1;
    }
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    return ptr->data;
}