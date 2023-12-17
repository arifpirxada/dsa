#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Problem: Check if the parenthesis in an expression are matching
// Example: (2 + 4) * 9 + 8) - Parentheses are not matching

struct stack
{
    int size;
    int top;
    char *arr;
};

int parenthesisMatch(char expression[]);

int main()
{
    char exp[] = "(2 + 4) * (9 + 8)";

    if (parenthesisMatch(exp))
    {
        printf("Parenthesis match!");
    } else {
        printf("Parenthesis do not match!");
    }

    return 0;
}

int parenthesisMatch(char expression[])
{
    // Creating stack
    struct stack *parenthesisStack = (struct stack *)malloc(sizeof(struct stack));
    parenthesisStack->size = strlen(expression);
    parenthesisStack->top = -1;
    parenthesisStack->arr = (char *)malloc(parenthesisStack->size * sizeof(char));

    for (int i = 0; i < strlen(expression); i++)
    {

        if (expression[i] == '(')
        {

            // Push element into the stack
            parenthesisStack->top++;
            parenthesisStack->arr[parenthesisStack->top] = expression[i];
        }
        else if (expression[i] == ')')
        {

            // Pop element from stack
            if (parenthesisStack->top < 0)
            {
                return 0;
            }
            parenthesisStack->top--;
        }
    }

    if (parenthesisStack->top != -1)
    {
        return 0;
    }
    return 1;
}