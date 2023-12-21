#include <stddef.h>
// https://leetcode.com/problems/merge-two-sorted-lists/

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (!head || head->next == NULL) {
        return head;
    }

    struct ListNode *ptr = head->next;
    struct ListNode *previousPtr = head;
    struct ListNode *temp;

    while (ptr != NULL) {
        if (ptr->val == previousPtr->val) {
            temp = ptr;
            previousPtr->next = ptr->next;
            ptr = ptr->next;

            free(temp);
        } else {
            previousPtr = ptr;
            ptr = ptr->next;
        }
    }

    return head;
}