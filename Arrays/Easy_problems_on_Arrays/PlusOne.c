#include <stdio.h>
#include <stdlib.h>

// Link: "https://leetcode.com/problems/plus-one/"

int* plusOne(int* digits, int digitsSize, int* returnSize);

int main()
{
    int nums[] = {1, 2, 3}, target = 5, returnSize, i;
    int *result = plusOne(nums, 3, &returnSize);
    
    for (i = 0; i < returnSize; i++)
    {
        printf("Element: %d\n", result[i]);
    }

    free(result);

    return 0;
}

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    for (int i = digitsSize - 1; i >= 0; i--) {
        if (digits[i] < 9) {
            digits[i] += 1;
            *returnSize = digitsSize;
            return digits;
        }
        digits[i] = 0;
    }
    *returnSize = digitsSize + 1;
    int* newDigits = realloc(digits, (*returnSize) * sizeof(int));
    if (newDigits == NULL) {
        return digits;
    }

    digits = newDigits;
    for (int j = 1; j < *returnSize; j++) {
        digits[j] = 0;
    }
    digits[0] = 1;
    return digits;
}