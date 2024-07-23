// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/submissions/1297681401/

struct ListNode* deleteMiddle(struct ListNode* head) {
    int middleIndex, size = 0, i = 0;
    struct ListNode* ptr = head;
    struct ListNode* prev = NULL;

    while (ptr) {
        size++;
        ptr = ptr->next;
    }

    middleIndex = size / 2;
    ptr = head;

    while (ptr) {
        if (i == middleIndex) {
            // Remove node
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