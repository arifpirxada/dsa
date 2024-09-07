// https://leetcode.com/problems/merge-nodes-in-between-zeros/

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ptr = head;
        ListNode* ptr2 = head->next;

        while (ptr2) {
            ptr->val = ptr->val + ptr2->val;
            if (ptr2->val == 0) {
                if (ptr2->next) {
                    ptr->next = ptr2;
                    ptr = ptr2;
                } else {
                    ptr->next = nullptr;
                }
            }
            ptr2 = ptr2->next;
        }
        ptr = nullptr;

        return head;
    }
};