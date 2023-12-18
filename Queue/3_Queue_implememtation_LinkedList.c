#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traverseQueue(struct Node *head);
int isEmpty(struct Node *ptr);
void enqueue(struct Node **front, struct Node **rear, int element);
int dequeue(struct Node **front);

int main()
{
    struct Node *front = NULL;
    struct Node *rear = NULL;

    enqueue(&front, &rear, 44);
    enqueue(&front, &rear, 32);
    enqueue(&front, &rear, 19);
    enqueue(&front, &rear, 86);

    dequeue(&front);

    traverseQueue(front);

    return 0;
}

int isEmpty(struct Node *front)
{
    if (front == NULL)
    {
        return 1;
    }
    return 0;
}

void traverseQueue(struct Node *head)
{
    while (head != NULL)
    {
        printf("Element: %d\n", head->data);
        head = head->next;
    }
}

void enqueue(struct Node **front, struct Node **rear, int element)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Queue overflow!\n");
    }
    else
    {
        newNode->data = element;
        newNode->next = NULL;
        if (*front == NULL)
        {
            *front = *rear = newNode;
        }
        else
        {
            (*rear)->next = newNode;
            *rear = newNode;
        }
    }
}

int dequeue(struct Node **front)
{
    if (isEmpty(*front))
    {
        printf("Queue underflow!\n");
        return -1;
    }
    struct Node *nodeTobeDeleted = *front;
    int nodeData = (*front)->data;
    *front = (*front)->next;
    free(nodeTobeDeleted);

    return nodeData;
}