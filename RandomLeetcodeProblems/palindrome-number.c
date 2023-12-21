#include <stdbool.h>
// https://leetcode.com/problems/palindrome-number/

// Solve by reversing
bool isPalindrome(int x) {
    // Negative num can not be palindrome
    if (x < 0) {
        return false;
    }
    long long reversedX = 0, xCopy = x; // -> So as not to lose x while reversing
    int lastDigit;
    
    // Reverse the Number
    while (xCopy != 0) {
        lastDigit = xCopy % 10;
        reversedX = reversedX * 10 + lastDigit;
        xCopy /= 10;
    }

    if (reversedX == x) {
        return true;
    }
    return false;
}