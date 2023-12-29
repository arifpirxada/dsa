#include <stddef.h>
// https://leetcode.com/problems/reverse-linked-list-ii/

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    struct ListNode *dummy = malloc(sizeof(struct ListNode));
    dummy->next = head;

    struct ListNode *prev = dummy;
    for (int i = 1; i < left; ++i) {
        prev = prev->next;
    }

    struct ListNode *current = prev->next;
    struct ListNode *next = NULL;
    struct ListNode *tail = current;

    for (int i = left; i <= right; ++i) {
        struct ListNode *temp = current->next;
        current->next = next;
        next = current;
        current = temp;
    }

    prev->next = next;
    tail->next = current;

    return dummy->next;
}