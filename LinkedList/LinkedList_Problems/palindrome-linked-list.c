#include <stddef.h>
#include <stdbool.h>
// https://leetcode.com/problems/palindrome-linked-list/

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

bool isPalindrome(struct ListNode* head) {
    if (head == NULL) {
        return true;
    }
    int i = 0, j;
    struct ListNode *ptr = head;

    // Finding Linked List size
    while (ptr != NULL) {
        ptr = ptr->next;
        i++;
    }
    
    ptr = head; // ptr reset
    int *arr = (int *)malloc(i * sizeof(int));

    // Storing linked list values in array
    for (j = 0; j < i; j++) {
        arr[j] = ptr->val;
        ptr = ptr->next;
    }

    ptr = head; // ptr reset
    // comparing Linked List and Array (in reverse order)
    while (ptr != NULL) {
        i--;
        if (ptr->val != arr[i]) {
            return false;
        }
        ptr = ptr->next;
    }

    return true;
}