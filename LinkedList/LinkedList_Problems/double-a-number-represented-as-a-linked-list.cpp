// https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/

class Solution {
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next;

        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    ListNode* doubleIt(ListNode* head) {
        if (!head) return head;
        head = reverseList(head);

        ListNode* ptr = head;
        int carry = 0;
        
        while (ptr) {
            int val = ptr->val * 2 + carry;
            ptr->val = val % 10;
            carry = val / 10;

            if (!ptr->next && carry > 0) {
                ptr->next = new ListNode(carry);
                carry = 0;
                break;
            }

            ptr = ptr->next;
        }

        head = reverseList(head);
        return head;
    }
};