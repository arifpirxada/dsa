// https://leetcode.com/problems/powx-n/

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        long long p = n;
        if (p < 0) {
            x = 1 / x;
            p = -p;
        }

        if (n % 2 == 0) {
            double half = myPow(x, p / 2);
            return half * half;
        } else {
            return x * myPow(x, p - 1);
        }
    }
};