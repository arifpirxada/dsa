#include <stddef.h>
// https://leetcode.com/problems/middle-of-the-linked-list/
// 876 - leetcode

// Definition for singly-linked list.
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *middleNode(struct ListNode *head)
{
    struct ListNode *ptr = head;

    while (ptr != NULL && ptr->next != NULL)
    {
        head = head->next;
        ptr = ptr->next->next;
    }

    return head;
}