// https://leetcode.com/problems/valid-palindrome/

class Solution {
public:
    bool isAlnum(char c) {
        return isalnum(c);
    }

    bool check(string &s, int i, int j) {
        if (i >= j) return true;

        if (!isAlnum(s[i])) return check(s, i + 1, j);
        if (!isAlnum(s[j])) return check(s, i, j - 1);

        if (tolower(s[i]) != tolower(s[j])) return false;

        return check(s, i + 1, j - 1);
    }

    bool isPalindrome(string s) {
        return check(s, 0, s.size() - 1);
    }
};