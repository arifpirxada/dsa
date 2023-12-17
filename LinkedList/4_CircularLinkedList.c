#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Circular Linked List: It is a type of Linked List whose last node has a pointer to head instead of NULL

void traverseLinkedList(struct Node *head);

struct Node *beginningInsertion(struct Node *head, int element);

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
    third->next = head;

    head = beginningInsertion(head, 55);

    traverseLinkedList(head);

    return 0;
}

// 1. Circular Linked List traverse

void traverseLinkedList(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

// 2. Insert at first

struct Node *beginningInsertion(struct Node *head, int element)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *ptr = head;

    while (ptr->next != head)
    {
        ptr = ptr->next;
    }

    ptr->next = newNode;
    newNode->next = head;
    newNode->data = element;
    head = newNode;

    return newNode;
}