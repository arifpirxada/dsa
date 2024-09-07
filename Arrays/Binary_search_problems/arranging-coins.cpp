// https://leetcode.com/problems/arranging-coins/

class Solution {
public:
    int arrangeCoins(int n) {
        if (n == 1) return 1;
        int remaining = n, count = 0;

        for (int i = 1; i <= n; i++) {
            if (i > remaining) {
                return count;
            }
            remaining -= i;
            count++;
        }
        return -1;
    }
};
