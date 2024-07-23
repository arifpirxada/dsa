// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int size = 0;
    struct ListNode* ptr = head;
    struct ListNode* prev = NULL;

    while (ptr) {
        size++;
        ptr = ptr->next;
    }

    int indexFromLeft = size - n;
    int i = 0;
    ptr = head;

    while (ptr) {
        if (indexFromLeft == i) {
            if (prev) {
                prev->next = ptr->next;
                free(ptr);
                return head;
            } else {
                head = head->next;
                free(ptr);
                return head;
            }
        }
        i++;
        prev = ptr;
        ptr = ptr->next;
    }

    return head;
}