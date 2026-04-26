// https://leetcode.com/problems/valid-digit-number/

class Solution {
public:
    bool validDigit(int n, int x) {
        int d;
        bool contains = false;
        while (n > 0) {
            d = n % 10;
            if (d == x && n >= 10) {
                contains = true;
            };
            n = n / 10;
        }
        if (d == x) return false;
        return contains;
    }
};