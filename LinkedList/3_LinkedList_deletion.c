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

struct Node *beginningDeletion(struct Node *head);
struct Node *betweenDeletion(struct Node *head, int index);
struct Node *endDeletion(struct Node *head);
struct Node *deleteByValue(struct Node *head, int value);

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

    // head = beginningDeletion(head);

    // head = betweenDeletion(head, 2);

    // head = endDeletion(head);

    // head = deleteByValue(head, 52);

    traverseLinkedList(head);

    return 0;
}

struct Node *beginningDeletion(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);

    return head;
}

struct Node *betweenDeletion(struct Node *head, int index)
{
    int i = 0;
    struct Node *ptr = head;

    // Condition for first node
    if (index == 0)
    {
        head = head->next;
        free(ptr);

        return head;
    }

    struct Node *nodeToBeDeleted = head->next;

    while (i < index - 1)
    {
        // Condition for checking if index is greater than Linked List size
        if (nodeToBeDeleted->next == NULL)
        {
            return head;
        }
        ptr = ptr->next;
        nodeToBeDeleted = nodeToBeDeleted->next;
        i++;
    }

    ptr->next = nodeToBeDeleted->next;
    free(nodeToBeDeleted);

    return head;
}

struct Node *endDeletion(struct Node *head)
{
    struct Node *ptr = head;
    struct Node *nodeToBeDeleted = ptr->next;

    while (nodeToBeDeleted->next != NULL)
    {
        nodeToBeDeleted = nodeToBeDeleted->next;
        ptr = ptr->next;
    }
    ptr->next = NULL;
    free(nodeToBeDeleted);

    return head;
}

struct Node *deleteByValue(struct Node *head, int value)
{
    struct Node *ptr = head;
    struct Node *nodeToBeDeleted = head->next;

    // Checking if first node contains the value
    if (ptr->data == value)
    {
        head = ptr->next;
        free(ptr);

        return head;
    }

    while (nodeToBeDeleted->next != NULL)
    {
        if (nodeToBeDeleted->data == value)
        {
            ptr->next = nodeToBeDeleted->next;
            free(nodeToBeDeleted);

            return head;
        }
        ptr = ptr->next;
    }

    return head;
}