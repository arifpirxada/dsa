// https://leetcode.com/problems/rotate-list/

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || !head || !head->next) return head;
        int len = 0;
        ListNode* ptr = head;

        while (ptr) {
            len++;
            ptr = ptr->next;
        }

        k = k % len;
        if (k == 0) return head;

        len -= k;
        ptr = head;
        for (int i{}; i < len - 1; i++) {
            ptr = ptr->next;
        }
        ListNode* prev = ptr;
        ptr = ptr->next;
        prev->next = nullptr;
        prev = head;
        head = ptr;

        while (ptr->next) {
            ptr = ptr->next;
        }
        ptr->next = prev;
        return head;
    }
};

// new 

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || !head || !head->next) return head;
        int times = 0;
        ListNode* ptr = head;
        ListNode* prev = NULL;

        int len = 0;
        while (ptr) {
            ptr = ptr->next;
            len++;
        }

        ptr = head;
        k = k % len;
        while (times < k) {
            if (!ptr->next) {
                ptr->next = head;
                head = ptr;
                prev->next = NULL;
                ptr = head;
                prev = NULL;
                times++;
            } else {
                prev = ptr;
                ptr = ptr->next;
            }
        }

        return head;
    }
};