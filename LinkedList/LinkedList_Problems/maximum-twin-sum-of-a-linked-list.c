// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/

int pairSum(struct ListNode* head) {
    int size = 0;
    int maxTwinSum;
    struct ListNode* ptr = head;
    // Knowing the size
    while (ptr) {
        size++;
        ptr = ptr->next;
    }

    // Creating an array to store list values
    int* arr = (int*)malloc(size * sizeof(int));
    
    int i = 0, j = size - 1;
    ptr = head;
    while (ptr) {
        arr[i++] = ptr->val;
        ptr = ptr->next;
    }

    maxTwinSum = arr[0] + arr[j];
    for (i = 0; i < size/2; i++) {
        if (arr[i] + arr[j] > maxTwinSum) {
            maxTwinSum = arr[i] + arr[j];
        }
        j--;
    }

    return maxTwinSum;
}