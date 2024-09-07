// https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/

class Solution {
public:
    int getGCD(int a, int b) {
        if (a < b) {
            std::swap(a, b);
        }
        int temp;
        while (a % b != 0) {
            temp = b;
            b = a % b;
            a = temp; 
        }
        return b;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* ptr = head->next;
        ListNode* backPtr = head;

        while (ptr) {
            int gcd = getGCD(ptr->val, backPtr->val);
            ListNode* newNode = new ListNode(gcd);
            backPtr->next = newNode;
            newNode->next = ptr;
            backPtr = ptr;
            ptr = ptr->next;
        }
        return head;
    }
};