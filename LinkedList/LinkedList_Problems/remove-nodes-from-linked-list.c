// https://leetcode.com/problems/remove-nodes-from-linked-list/

struct ListNode *reverseList(struct ListNode *head)
{
    struct ListNode *ptr = NULL;
    struct ListNode *prevNode;

    while (head != NULL)
    {
        prevNode = head;
        head = head->next;
        prevNode->next = ptr;
        ptr = prevNode;
    }

    return ptr;
}

struct ListNode* removeNodes(struct ListNode* head) {
    if (!head || !head->next) return head;
    head = reverseList(head);

    int biggest = head->val;

    struct ListNode* ptr = head;
    struct ListNode* prev = NULL;
    while (ptr) {
        if (biggest <= ptr->val) {
            biggest = ptr->val;
            prev = ptr;
            ptr = ptr->next;
        } else {
            // Remove the node
           struct ListNode* temp = ptr;
            ptr = ptr->next;
            if (prev) {
                prev->next = ptr;
            }
            free(temp);
        }
    }

    head = reverseList(head);

    return head;
}