// https://leetcode.com/problems/string-to-integer-atoi/


// Not optimized solution
class Solution {
private:
    int getDigit(char digit) {
        if (isdigit(digit)) {
            if (digit == '0') {
                return 0;
            } else if (digit == '1') {
                return 1;
            } else if (digit == '2') {
                return 2;
            } else if (digit == '3') {
                return 3;
            } else if (digit == '4') {
                return 4;
            } else if (digit == '5') {
                return 5;
            } else if (digit == '6') {
                return 6;
            } else if (digit == '7') {
                return 7;
            } else if (digit == '8') {
                return 8;
            } else if (digit == '9') {
                return 9;
            }
        }
        return -1;
    }
public:
    int myAtoi(string s) {
        int sign = 1;
        long ans = 0;
        int plusTimes = 0;

        if (s[0] != '-' && s[0] != '+' && !isdigit(s[0]) && s[0] != ' ') {
            return 0;
        }
        int i = 0;
        while (s[i] == ' ') {
            i++;
        }

        for (i = i; i < s.size(); i++) {
            if (sign == -1 && s[i] == '+') {
                return (ans * sign);
            }
            if (s[i] == '+') {
                plusTimes++;
                if (plusTimes > 1) {
                    return (ans * sign);
                }
            }
            if (i > 0 && s[i] == '+' && s[i - 1] != ' ') {
                return (ans * sign);
            }
            if (i > 0 && s[i] == '-' && s[i - 1] != ' ') {
                int j = i;
                ans *= sign;
                return ans;
            } else if (s[i] == '-') {
                sign = -1;
            } else {
                int digit = getDigit(s[i]);
                if (digit != -1) {
                    if ((ans * 10) + digit <= INT_MAX) {
                        ans = (ans * 10) + digit;
                    } else {
                        return sign == 1 ? INT_MAX : INT_MIN;
                    }
                } else {
                    if (s[i] == '-' || s[i] == '+') {
                        continue;
                    }
                    ans *= sign;
                    return ans;
                }
            }
        }
        ans *= sign;
        return ans;
    }
};

// Better

class Solution {
public:
    int myAtoi(string s) {
        int sign = 1, i = 0;
        long ans = 0;
        while (s[i] == ' ') {
            i++;
        }
        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+') {
            i++;
        }

        while (s[i] >= '0' && s[i] <= '9') {
            int digit = s[i++] - '0';
            if ((ans * 10) + digit > INT_MAX) {
                return (sign == 1 ? INT_MAX : INT_MIN);
            }
            ans = (ans * 10) + digit;
        }
        return (ans * sign);
    }
};