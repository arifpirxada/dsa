#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

// Doubly Linked List: It is a type of Linked List whose every node also has a pointer to it's previous node.

void traverseLinkedList(struct Node *ptr);

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    head->prev = NULL;
    head->next = second;

    second->data = 52;
    second->prev = head;
    second->next = third;

    third->data = 12;
    third->prev = second;
    third->next = NULL;

    traverseLinkedList(head);

    return 0;
}

// Doubly Linked List traverse

void traverseLinkedList(struct Node *ptr)
{
    printf("First to last:\n");
    do
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr->next != NULL);
    printf("Element: %d\n", ptr->data);

    printf("Last to first - Reverse traverse:\n");
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->prev;
    }
}