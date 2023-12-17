#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Infix, prefix & postfix are notations used for representing mathematical expressions - a + b * c + e
// 1. Infix: <operand><operator><operand>: a + b
// 2. Prefix: <operator><operand><operand>: +ab - operator at first
// 3. Postfix: <operand><operand><operator>: ab+ - operator at last

// * Prefix & postfix are used instead of infix because it is easy for machine to do calculations (calculations are done in one iteration).
// * Postfix is mostly used

// Write a program to convert infix expression to postfix expression

struct stack
{
    int size;
    int top;
    char *arr;
};

char *infixToPostfix(char *infix);

int main()
{
    char *infixExp = "a+b*c+e"; // Postfix: abc*+e+
    printf("Postfix: %s", infixToPostfix(infixExp));

    return 0;
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct stack *ptr)
{
    if (ptr->top < 0)
    {
        return 1;
    }
    return 0;
}

int stackTop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        return -1;
    }
    return ptr->arr[ptr->top];
}

void push(struct stack *ptr, int element)
{
    if (isFull(ptr))
    {
        printf("Stack overflow");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = element;
    }
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack underflow");
        return -1;
    }

    int elementToBeDeleted = ptr->arr[ptr->top];
    ptr->top--;

    return elementToBeDeleted;
}

int isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
    {
        return 1;
    }
    return 0;
}

int precedence(char c)
{
    if (c == '*' || c == '/')
    {
        return 3;
    }
    if (c == '+' || c == '-')
    {
        return 2;
    }
    return 0;
}

char *infixToPostfix(char *infix)
{
    // Creating a stack
    struct stack *operatorStack = (struct stack *)malloc(sizeof(struct stack));
    operatorStack->size = strlen(infix);
    operatorStack->top = -1;
    operatorStack->arr = (char *)malloc(operatorStack->size * sizeof(char *));

    char *postfix = (char *)malloc(strlen(infix) * sizeof(char));

    int i = 0, j = 0;

    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else if (isOperator(infix[i]))
        {
            if (precedence(infix[i]) > precedence(stackTop(operatorStack)))
            {
                push(operatorStack, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(operatorStack);
                j++;
            }
        }
    }

    while (!isEmpty(operatorStack))
    {
        postfix[j] = pop(operatorStack);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}