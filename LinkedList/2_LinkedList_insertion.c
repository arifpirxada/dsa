#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traverseLinkedList(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Insertion functions

struct Node *beginningInsertion(struct Node *head, int element);
struct Node *betweenInsertion(struct Node *head, int index, int element);
struct Node *endInsertion(struct Node *head, int element);
struct Node *insertAfterNode(struct Node *ptr, int element);

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 52;
    second->next = third;

    third->data = 12;
    third->next = NULL;

    // head = beginningInsertion(head, 33);

    // betweenInsertion(head, 2, 77);

    // endInsertion(head, 66);

    insertAfterNode(second, 99);

    traverseLinkedList(head);

    return 0;
}

struct Node *beginningInsertion(struct Node *head, int element)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    
    ptr->data = element;
    ptr->next = head;

    return ptr;
}

struct Node *betweenInsertion(struct Node *head, int index, int element)
{
    int i = 1;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *ptr = head;

    while (i < index) {
        ptr = ptr->next;
        i++;
    }

    newNode->next = ptr->next;
    newNode->data = element;
    ptr->next = newNode;

    return head;
}

struct Node *endInsertion(struct Node *head, int element)
{
    struct Node *ptr = head;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    ptr->next = newNode;
    newNode->next = NULL;
    newNode->data = element;

    return head;
}

struct Node *insertAfterNode(struct Node *ptr, int element)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = element;
    newNode->next = ptr->next;
    ptr->next = newNode;

    return ptr;
}