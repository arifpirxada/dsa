// https://leetcode.com/problems/baseball-game/

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

int calPoints(char** operations, int operationsSize) {
    int i;
    int sum = 0;
    struct stack *st = (struct stack *)malloc(sizeof(struct stack));
    st->size = operationsSize;
    st->top = -1;
    st->arr = (int *)malloc(st->size * sizeof(int));

    for (i = 0; i < operationsSize; i++) {
        if (strcmp(operations[i], "+") == 0) {
            // sum of the previous two scores.
            push(st, st->arr[st->top] + st->arr[st->top - 1]);
        } else if (strcmp(operations[i], "D") == 0) {
            // double of the previous score.
            push(st, 2 * st->arr[st->top]);
        } else if (strcmp(operations[i], "C") == 0) {
            // removing it from the record.
            pop(st);
        } else {
            push(st, atoi(operations[i]));
        }
    }

    // Getting the sum of elements in stack
    i = st->top;

    while (i >= 0) {
        sum += (int)st->arr[i];
        i--;
    }

    free(st->arr);
    free(st);

    return sum;
}