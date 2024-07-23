// https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/

struct ListNode* doubleIt(struct ListNode* head){
    // Knowing the size
    int size = 0;
    struct ListNode* ptr = head;
    
    while (ptr) {
        size++;
        /* We had to the len of node.val and then update size. 
        But here in the question 0 <= Node.val <= 9 */ 
        ptr = ptr->next;
    }

    char* digits_string = (char*)malloc((size + 2) * sizeof(char));

    ptr = head;
    int k = 0;
    // 1. Converting elements of linked list into string array. 
    while (ptr) {
        digits_string[k++] = ptr->val + '0';
        ptr = ptr->next;
    }

    // 2. Convert the digits_string into integer.
    digits_string[k] = '\0';  // Null-terminate the string.
    long int digits_integer = atol(digits_string);

    // 3. Double the integer by multiplying with 2.
    digits_integer *= 2;

    // 4. Convert the integer back to string.
    sprintf(digits_string, "%d", digits_integer);

    // 5. Finally convert the integer into list.
    struct ListNode* prev;
    ptr = head;

    for (int i = 0; i < size; i++) {
        if (ptr) {
            ptr->val = digits_string[i];
        } else {
            ptr = (struct ListNode*)malloc(sizeof(struct ListNode));
            prev->next = ptr;
            ptr->next = NULL;
            ptr->val = digits_string[i];
        }
        prev = ptr;
        ptr = ptr->next;
    }

    free(digits_string);
    return head;
}