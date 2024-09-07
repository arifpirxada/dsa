// https://leetcode.com/problems/pass-the-pillow/

class Solution {
public:
    int passThePillow(int n, int time) {
        if (time / (n - 1) % 2 == 0) {
            // even
            time %= (n - 1);
            return (time + 1);
        } else {
            // odd
            time %= (n - 1);
            return (n - time);
        }
    }
};