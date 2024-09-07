// https://leetcode.com/problems/swap-nodes-in-pairs/

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* ptr = head->next;
        ListNode* backPtr = head;
        ListNode* firstPtr = nullptr;
        head = ptr;

        while(ptr && backPtr) {
            backPtr->next = ptr->next;
            ptr->next = backPtr;
            firstPtr = backPtr;
            backPtr = backPtr->next;
            if (backPtr) {
                ptr = backPtr->next;
                if (ptr) {
                    firstPtr->next = ptr;
                } else {
                    firstPtr->next = backPtr;
                }
            }
        }
        return head;
    }
};