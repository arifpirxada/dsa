// https://leetcode.com/problems/reverse-only-letters/

class Solution {
public:
    bool isChar(char ch) {
        if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122)) {
            return true;
        }
        return false;
    }
    string reverseOnlyLetters(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            while (i < j && !isChar(s[i])) {
                i++;
            }
            while (i < j && !isChar(s[j])) {
                j--;
            }
            if (i < j) {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};