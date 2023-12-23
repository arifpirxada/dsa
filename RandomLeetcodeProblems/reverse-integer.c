#include <limits.h>
// https://leetcode.com/problems/reverse-integer/

int reverse(int x){
    if (x == INT_MIN) {
        return 0;
    }

    int isNegative = 0;
    long long reversedX = 0;

    if (x < 0) {
        isNegative = 1;
        x = abs(x);
    }

    while (x > 0) {
        reversedX = (reversedX * 10) + (x % 10);
        x /= 10;
        if (reversedX > INT_MAX || reversedX < INT_MIN) {
            return 0;
        }
    }

    if (isNegative) {
        reversedX *= -1;
    }
    return (int)reversedX;
}