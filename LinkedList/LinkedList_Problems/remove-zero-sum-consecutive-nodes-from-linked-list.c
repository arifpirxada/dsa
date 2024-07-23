// https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/

struct ListNode* removeZeroSumSublists(struct ListNode* head) {
    // Storing node values in array
    int size = 0;
    struct ListNode* ptr = head;
    
    while(ptr) {
        size++;
        ptr = ptr->next;
    }

    int* arr = (int*)malloc(size * sizeof(int));
    ptr = head;
    int i = 0;

    while(ptr) {
        arr[i++] = ptr->val;
        ptr = ptr->next;
    }

    // finding subarrays whose sum is zero

    int sum;
    for (i = 0; i < size; i++) {
        sum = arr[i];
        if (sum == 0) {
            arr[i] = INT_MAX;
            continue;
        }
        for (int j = i + 1; j < size; j++) {
            sum += arr[j];
            if (sum == 0) {
                // set all the element from i to j NULL
                for (int k = i; k <= j; k++) {
                    arr[k] = INT_MAX;
                }
                i = j;
                break;
            }

        }
    }

    // Convert back to linked list

    ptr = (struct ListNode*)malloc(sizeof(struct ListNode));
    head = ptr;
    ptr->next = NULL;
    
    for (i = 0; i < size; i++) {
        if (arr[i] != INT_MAX) {
            struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
            newNode->val = arr[i];
            newNode->next = NULL;
            ptr->next = newNode;
            ptr = newNode;
        }
    }
    free(arr);
    return head->next;
}