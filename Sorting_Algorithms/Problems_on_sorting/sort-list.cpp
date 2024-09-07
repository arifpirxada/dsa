// https://leetcode.com/problems/sort-list/


// TIME LIMIT EXCEEDS: Bubble sort
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        int last = 0;
        ListNode* ptr = head;
        ListNode* next;

        while (ptr) {
            last++;
            ptr = ptr->next;
        }

        while (last > 0) {
            int i = 1;
            ptr = head;
            next = ptr->next;
            while (i < last) {
                if (ptr->val > next->val) {
                    // swap
                    int temp = ptr->val;
                    ptr->val = next->val;
                    next->val = temp;
                }
                ptr = next;
                next = next->next;
                i++;
            }
            last--;
        }

        return head;
    }
};

// USING MERGE SORT

class Solution {
private:
    ListNode* findMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode dummy;
        ListNode* tail = &dummy;
        
        while (left && right) {
            if (left->val < right->val) {
                tail->next = left;
                left = left->next;
            } else {
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }
        
        if (left) tail->next = left;
        if (right) tail->next = right;
        
        return dummy.next;
    }
    
    ListNode* mergeSort(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        
        ListNode* mid = findMid(head);
        ListNode* right = mid->next;
        mid->next = nullptr;
        
        ListNode* left = mergeSort(head);
        right = mergeSort(right);
        
        return merge(left, right);
    }
    
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        return mergeSort(head);
    }
};