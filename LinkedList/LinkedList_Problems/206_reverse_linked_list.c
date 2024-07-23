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

// New way

struct ListNode* reverse(struct ListNode* hea) {
    // Reverses and Returns size
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* next = NULL;

    while(curr) {
        next = curr->next; 
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}