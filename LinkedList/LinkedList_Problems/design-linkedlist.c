#include <stddef.h>
// https://leetcode.com/problems/design-linked-list/

typedef struct {
    int val;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
} MyLinkedList;

Node *createNode(int val)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->val = val;
    return newNode;
}

MyLinkedList* myLinkedListCreate() {
    MyLinkedList *obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    obj->head = NULL;
    return obj;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    int i = 0;
    Node *ptr = obj->head;
    if (index == 0 && !ptr) {
        return -1;
    }
    if (index == 0 && ptr) {
        return ptr->val;
    }

    while (ptr != NULL) {
        if (i == index) {
            return ptr->val;
        }
        ptr = ptr->next;
        i++;
    }
    return -1;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    if (obj->head == NULL) {
        obj->head = createNode(val);
    } else {
        Node *temp = obj->head;
        obj->head = createNode(val);
        obj->head->next = temp;
    }
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    if (obj->head == NULL) {
        myLinkedListAddAtHead(obj, val);
        return;
    }

    Node *ptr = obj->head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    ptr->next = createNode(val);
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (obj->head == NULL) {
        if (index == 0) {
            obj->head = createNode(val);
        }
        return;
    }

    Node *ptr = obj->head;
    Node *newNode = createNode(val);

    if (index == 0) {
        newNode->next = obj->head;
        obj->head = newNode;
        return;
    }

    for (int i = 0; i < index - 1 && ptr != NULL; i++) {
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        return;
    }
    newNode->next = ptr->next;
    ptr->next = newNode;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (obj == NULL || obj->head == NULL) {
        // Empty linked list, nothing to delete
        return;
    }

    if (index == 0) {
        // Delete the head of the linked list
        Node* deleteNode = obj->head;
        obj->head = obj->head->next;
        free(deleteNode);
        return;
    }

    int i = 1;
    Node* ptr = obj->head;
    while (ptr != NULL) {
        if (i == index) {
            Node* deleteNode = ptr->next;
            if (deleteNode != NULL) {
                ptr->next = deleteNode->next;
                free(deleteNode);
            }
            break;
        }
        ptr = ptr->next;
        i++;
    }
}

void myLinkedListFree(MyLinkedList* obj) {
    Node* ptr = obj->head;
    Node* temp;
    while(ptr != NULL) {
        temp = ptr;
        ptr = ptr->next;
        free(temp);
    }
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/