#include <stddef.h>
// https://leetcode.com/problems/remove-linked-list-elements/

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode *prevPtr = NULL;
    struct ListNode *ptr = head;
    struct ListNode *deleteNode;

    while (ptr != NULL) {
        if (ptr->val == val) {
            if (prevPtr == NULL) {
                head = ptr->next;
            } else {
                prevPtr->next = ptr->next;
            }

            deleteNode = ptr;
            ptr = ptr->next;

            free(deleteNode);
        } else {
            prevPtr = ptr;
            ptr = ptr->next;
        }
    }

    return head;
}