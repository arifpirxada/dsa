#include <stdio.h>

int factorial(int n);
int twoPower(int n);

int main()
{
    int num = 3;

    // Factorial:
    // int f = factorial(num);
    // printf("Factorial: %d", f);

    // Two power:
    // int t = twoPower(3);
    // printf("2^n: %d", t);

    return 0;
}

int factorial(int n)
{
    // Base case
    if (n == 1 || n == 0)
    {
        return 1;
    }

    int recursionResult = factorial(n - 1); // Recursion call
    int result = n * recursionResult; // small calc

    return result;
}

int twoPower(int n)
{
    if (n == 0)
    {
        return 1;
    }

    int recursionResult = twoPower(n - 1);
    int result = 2 * recursionResult;

    return result;
}