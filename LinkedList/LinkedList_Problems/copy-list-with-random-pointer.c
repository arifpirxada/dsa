// https://leetcode.com/problems/copy-list-with-random-pointer/

/**
 * Definition for a Node.
 * struct Node {
 *     int val;ext;
 *     struct Node *random;
 * };
 *     struct Node *n
 */

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->next = NULL;
    newNode->random = NULL;
    return newNode;
}

struct Node* copyRandomList(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }

	struct Node* ptr = head;

    // Insert copy of each node in the list in front of them
    while (ptr) {
        struct Node* newNode = createNode(ptr->val);
        newNode->next = ptr->next;
        ptr->next = newNode;
        ptr = newNode->next;
    }

    // Assign random Node
    ptr = head;
    while (ptr) {
        if (ptr->random) {
            ptr->next->random = ptr->random->next;
        }
        ptr = ptr->next->next;
    }

    // Separate copied and original nodes
    ptr = head;
    struct Node* newHead = ptr->next;
    struct Node* newPtr = newHead;

    while (ptr) {
        ptr->next = ptr->next->next;
        if (newPtr->next) {
            newPtr->next = newPtr->next->next;
        }
        newPtr = newPtr->next;
        ptr = ptr->next;
    }

    return newHead;
}