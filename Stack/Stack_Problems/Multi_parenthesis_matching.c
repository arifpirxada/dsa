#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Leetcode: https://leetcode.com/problems/valid-parentheses/

// Problem: Check if the parenthesis in an expression are matching
// * Expression also contains curly braces and brackets.
// Example: {(2 + 4) * [2(9 + 8)]} - Parentheses are matching

struct stack
{
    int size;
    int top;
    char *arr;
};

int multiParenthesisMatch(char expression[]);

int main()
{
    char exp[] = "([)]";

    if (multiParenthesisMatch(exp))
    {
        printf("Parenthesis match!");
    }
    else
    {
        printf("Parenthesis do not match!");
    }

    return 0;
}

int match(char a, char b)
{
    if (a == '(' && b == ')')
    {
        return 1;
    }
    if (a == '[' && b == ']')
    {
        return 1;
    }
    if (a == '{' && b == '}')
    {
        return 1;
    }
    return 0;
}

int multiParenthesisMatch(char expression[])
{
    // Creating stack
    struct stack *parenthesisStack = (struct stack *)malloc(sizeof(struct stack));
    parenthesisStack->size = strlen(expression);
    parenthesisStack->top = -1;
    parenthesisStack->arr = (char *)malloc(parenthesisStack->size * sizeof(char));

    for (int i = 0; i < strlen(expression); i++)
    {

        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{')
        {

            // Push element into the stack
            parenthesisStack->top++;
            parenthesisStack->arr[parenthesisStack->top] = expression[i];
        }
        else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}')
        {

            // Pop element from stack
            if (parenthesisStack->top < 0)
            {
                return 0;
            }
            // Check if the current parenthesis is similar to the last parenthesis
            if (match(parenthesisStack->arr[parenthesisStack->top], expression[i]))
            {
                parenthesisStack->top--;
            }
            else
            {
                return 0;
            }
        }
    }

    if (parenthesisStack->top != -1)
    {
        return 0;
    }
    return 1;
}