// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* ptr = head;
        ListNode* back = nullptr;
        int duplicate;

        while (ptr) {
            if (ptr->next && ptr->val == ptr->next->val) {
                duplicate = ptr->val;
                while (ptr && ptr->val == duplicate) {
                    ptr = ptr->next;
                }
                if (!back) {
                    head = ptr;
                } else {
                    back->next = ptr;
                }
            } else {
                back = ptr;
                ptr = ptr->next;
            }
        }

        return head;
    }
};