// https://leetcode.com/problems/swapping-nodes-in-a-linked-list

void swap(struct ListNode* left, struct ListNode* right) {
    int temp = left->val;
    left->val = right->val;
    right->val = temp;
}

struct ListNode* swapNodes(struct ListNode* head, int k) {
    struct ListNode* ptr = head;
    struct ListNode* left;
    struct ListNode* right;

    int len = 0;

    // finding the length and setting the left node
    while (ptr) {
        len++;
        if (k == len) {
            left = ptr;
        }
        ptr = ptr->next;
    }

    ptr = head;
    int i = 1;
    while (ptr) {
        if (i == len - (k - 1)) {
            right = ptr;
            break;
        }
        ptr = ptr->next;
        i++;
    }
    swap(left, right);

    return head;
}