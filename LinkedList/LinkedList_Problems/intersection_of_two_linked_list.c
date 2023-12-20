#include <stddef.h>
// https://leetcode.com/problems/intersection-of-two-linked-lists/

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int len1 = 0, len2 = 0;
    struct ListNode *a = headA;
    struct ListNode *b = headB;

    struct ListNode *countLenA = headA;
    struct ListNode *countLenB = headB;

    while (1) {
        if (countLenA != NULL) {
            countLenA = countLenA->next;
            len1++;
        }
        if (countLenB != NULL) {
            countLenB = countLenB->next;
            len2++;
        }
        if (countLenA == NULL && countLenB == NULL) {
            break;
        }
    }

    while(len1>len2) {
        len1--;
        a=a->next;
    }
    
    while(len2>len1) {
        len2--;
        b=b->next;
    }

    while(a!=b) {
        a=a->next;
        b=b->next;
    }

    return a;
}