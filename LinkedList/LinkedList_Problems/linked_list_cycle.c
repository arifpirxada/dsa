#include <stddef.h>
#include <stdbool.h>
// https://leetcode.com/problems/linked-list-cycle/


// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return false;
    }

    struct ListNode *slow = head;
    struct ListNode *fast = head->next;

    while (slow != fast) {
        if (slow == NULL || fast == NULL || fast->next == NULL) {
            return false;
        }        
        slow = slow->next;
        fast = fast->next->next;
    }

    return true;
}