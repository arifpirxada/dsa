// leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/

struct stack
{
    int size;
    int top;
    int *arr;
};

// Push into stack

void push(struct stack *ptr, int element) {
    if (ptr->top > ptr->size - 1) {
        printf("Stack overflow!\n");
    } else {
        ptr->top++;
        ptr->arr[ptr->top] = element;
    }
}

// Pop from stack

void pop(struct stack *ptr) {
    if (ptr->top < 0) {
        printf("Stack underflow!\n");
    } else {
        ptr->top--;
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* finalPrices(int* prices, int pricesSize, int* returnSize) {
int i;
    *returnSize = pricesSize;

    // Creating a stack
    struct stack *st = (struct stack *)malloc(sizeof(struct stack));
    st->size = pricesSize;
    st->top = -1;
    st->arr = (int *)malloc(st->size * sizeof(int));

    int *answer = (int *)malloc(pricesSize * sizeof(int));

    for (i = 0; i < pricesSize; i++) {
        while (st->top >= 0 && prices[i] <= prices[st->arr[st->top]]) {
            answer[st->arr[st->top]] = prices[st->arr[st->top]] - prices[i];
            pop(st);
        }
        push(st, i);
    }

    while (st->top >= 0) {
        answer[st->arr[st->top]] = prices[st->arr[st->top]];
        pop(st);
    }

    free(st->arr);
    free(st);

    return answer;
}