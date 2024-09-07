// https://leetcode.com/problems/insertion-sort-list/

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = head;
        ListNode* ptr = head->next;

        while (ptr) {
            if (ptr->val >= prev->val) {
                prev = ptr;
                ptr = ptr->next;
            } else {
                ListNode* first = dummy;
                
                while (first->next->val < ptr->val) {
                    first = first->next;
                }

                prev->next = ptr->next;
                ptr->next = first->next;
                first->next = ptr;
                
                ptr = prev->next;
            }
        }

        ListNode* sortedHead = dummy->next;
        delete dummy;
        return sortedHead;
    }
};