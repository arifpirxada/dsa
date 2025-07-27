// https://leetcode.com/problems/happy-number/

class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast = n, temp = 0;
        temp = 0;
        while (slow > 0) {
            temp += (slow % 10) * (slow % 10);
            slow /= 10;
        }
        slow = temp;
        temp = 0;
        while (fast > 0) {
            temp += (fast % 10) * (fast % 10);
            fast /= 10;
        }
        fast = temp;
        temp = 0;
        while (fast > 0) {
            temp += (fast % 10) * (fast % 10);
            fast /= 10;
        }
        fast = temp;

        if (slow == 1 || fast == 1) {
            return true;
        }

        while (slow != fast) {
            temp = 0;
            while (slow > 0) {
                temp += (slow % 10) * (slow % 10);
                slow /= 10;
            }
            slow = temp;
            temp = 0;
            while (fast > 0) {
                temp += (fast % 10) * (fast % 10);
                fast /= 10;
            }
            fast = temp;
            temp = 0;
            while (fast > 0) {
                temp += (fast % 10) * (fast % 10);
                fast /= 10;
            }
            fast = temp;
            if (fast == 1 || slow == 1) {
                return true;
            }
        }
        return false;
    }
};