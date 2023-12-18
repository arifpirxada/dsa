#include <stddef.h>

// https://leetcode.com/problems/reverse-linked-list/
// 206 - leetcode

// Definition for singly-linked list.
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *reverseList(struct ListNode *head)
{
    struct ListNode *ptr = NULL;
    struct ListNode *prevNode;

    while (head != NULL)
    {
        prevNode = head;
        head = head->next;
        prevNode->next = ptr;
        ptr = prevNode;
    }

    return ptr;
}