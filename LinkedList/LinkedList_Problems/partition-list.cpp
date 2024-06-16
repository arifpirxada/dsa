// https://leetcode.com/problems/partition-list/

// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummyLess = new ListNode(0);
        ListNode* dummyGreaterEqual = new ListNode(0);
        ListNode* less = dummyLess;
        ListNode* greaterEqual = dummyGreaterEqual;

        while (head) {
            if (head->val < x) {
                less->next = head;
                less = less->next;
            } else {
                greaterEqual->next = head;
                greaterEqual = greaterEqual->next;
            }
            head = head->next;
        }

        greaterEqual->next = nullptr; 
        less->next = dummyGreaterEqual->next;

        return dummyLess->next;
    }
};
