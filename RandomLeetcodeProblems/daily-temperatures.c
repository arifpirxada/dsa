// https://leetcode.com/problems/daily-temperatures/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct stack
{
    int size;
    int top;
    int *arr;
} Stack;

Stack *createStack(int size)
{
    Stack *st = (Stack *)malloc(sizeof(Stack));
    st->size = size;
    st->top = -1;
    st->arr = (int *)malloc(size * sizeof(int));

    return st;
}

void push(Stack *st, int data)
{
    if (st->top == st->size - 1)
    {
        printf("Stack overflow");
    }
    else
    {
        st->top++;
        st->arr[st->top] = data;
    }
}

int pop(Stack *st)
{
    if (st->top < 0)
    {
        printf("Stack underflow");
        return -1;
    }
    int data = st->arr[st->top];
    st->top--;

    return data;
}

int *dailyTemperatures(int *temperatures, int temperaturesSize, int *returnSize)
{
    int i;
    int *ans = (int *)malloc(temperaturesSize * sizeof(int));
    Stack *st = createStack(temperaturesSize);

    for (i = temperaturesSize - 1; i >= 0; i--)
    {
        while (st->top >= 0)
        {
            if (temperatures[st->arr[st->top]] > temperatures[i])
            {
                ans[i] = st->arr[st->top] - i;
                break;
            }
            else
            {
                pop(st);
            }
        }

        if (st->top < 0)
        {
            ans[i] = 0;
        }

        push(st, i);
    }

    free(st->arr);
    free(st);
    *returnSize = temperaturesSize;
    return ans;
}