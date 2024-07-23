// https://leetcode.com/problems/linked-list-random-node/

typedef struct {
    int *arr;
    int size;
} Solution;


Solution* solutionCreate(struct ListNode* head) {
    struct ListNode* ptr = head;
    int size = 0;
    while (ptr) {
        size++;
        ptr = ptr->next;
    }

    Solution *curr_solution = (Solution*)malloc(sizeof(Solution));
    curr_solution->size = size;
    curr_solution->arr = (int*)malloc(curr_solution->size * sizeof(int));

    ptr = head;
    for (int i = 0; i < curr_solution->size; i++) {
        curr_solution->arr[i] = ptr->val;
        ptr = ptr->next;
    }
    return curr_solution;
}

int solutionGetRandom(Solution* obj) {
    int randomNumber = rand() % obj->size;
    return obj->arr[randomNumber];
}

void solutionFree(Solution* obj) {
    free(obj->arr);
    free(obj);
}