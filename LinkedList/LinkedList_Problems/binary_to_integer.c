#include <stddef.h>
#include <math.h>
// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

int getDecimalValue(struct ListNode* head) {
    double val = 0, power = -1;
    struct ListNode *ptr = head;

    // Finding Length
    while (ptr != NULL) {
        ptr = ptr->next;
        power++;
    }

    ptr = head;
    while (ptr != NULL) {
        val +=  ptr->val * pow(2, power);
        power--;
        ptr = ptr->next;
    }
    return val;
}