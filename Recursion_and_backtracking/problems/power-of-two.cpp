// https://leetcode.com/problems/power-of-two/

// Using recursion

class Solution {
public:
    bool helper(int n) {
        if (n == 2) return true;
        if (n % 2 != 0) return false;
        return helper(n / 2);
    }
    bool isPowerOfTwo(int n) {
        if (n == 1) return true;
        if (n == 0) return false;
        return helper(n);
    }
};

// Using bit manipulation

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};