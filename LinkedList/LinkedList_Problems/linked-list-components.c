#include <stddef.h>
// https://leetcode.com/problems/linked-list-components/

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

int numComponents(struct ListNode* head, int* nums, int numsSize) {
    int i, ans = numsSize, consec = 0, found, prev = 0;
    struct ListNode* ptr = head;

    while (ptr != NULL) {
        found = 0;
        for (i = 0; i < numsSize; i++) {
            if (nums[i] == ptr->val) {
                found = 1;
                break;
            }
        }

        if (found == 1) {
            if (prev == 1) {
                consec++;
            }
            prev = 1;
        }
        if (found == 0) {
            prev = 0;
        }

        ptr = ptr->next;
    }
    ans -= consec;

    return ans;
}