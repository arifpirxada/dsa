// https://leetcode.com/problems/merge-in-between-linked-lists/

struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2){
    if (!list1 || !list2 || !a || !b) return list1;

    struct ListNode* prev = list1;
    struct ListNode* ptr = list1->next;
    int index = 1;

    while (ptr) {
        if (index == a) {
            prev->next = list2;
        }

        if (index == b) {
            ptr = ptr->next;
            break;
        }

        prev = ptr;
        ptr = ptr->next;
        index++;
    }

    prev = list2;

    while (prev && prev->next) {
        prev = prev->next;
    }

    prev->next = ptr;

    if (a == 0) {
        return list2;   
    }

    return list1;

}