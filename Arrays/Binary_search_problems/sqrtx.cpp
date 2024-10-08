// https://leetcode.com/problems/sqrtx/

class Solution {
public:
    int mySqrt(int x) {
        if (x == 1) return x;
        long low = 0, high = x / 2, mid;

        while (low <= high) {
            mid = (low + high) / 2;
            if (mid * mid == x) {
                return mid;
            } else if ((mid + 1) * (mid + 1) > x && mid * mid < x) {
                return mid;
            } else if (mid * mid < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return -1;
    }
};