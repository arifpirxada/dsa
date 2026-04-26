// https://leetcode.com/problems/string-to-integer-atoi/

class Solution {
public:
    void atoiRecur(int i, string s, long long& ans) {
        if (i >= s.size() || ans >= INT_MAX || ans * -1 <= INT_MIN) return;
        if (s[i] < '0' || s[i] > '9') return;

        ans *= 10;
        ans += s[i] - '0';
        atoiRecur(i + 1, s, ans);
    }
    int myAtoi(string s) {
        int sign = 1;
        long long ans = 0;

        int i = 0;
        while (i < s.size() && s[i] == ' ') {
            i++;
        }
        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+') {
            i++;
        };

        atoiRecur(i, s, ans);

        if (ans * sign > INT_MAX) return INT_MAX;
        if (ans * sign < INT_MIN) return INT_MIN;
        return ans * sign;
    }
};