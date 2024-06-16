// https://leetcode.com/problems/find-first-palindromic-string-in-the-array/

class Solution {
public:
    bool isPalindromic(string str) {
        int size = str.size();
        char t;
        string temp = str;
        for (int i = 0; i < size / 2; i++) {
            t = temp[i];
            temp[i] = temp[size - i - 1];
            temp[size - i - 1] = t;
        }
        return str == temp;
    }
    string firstPalindrome(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            if (isPalindromic(words[i])) {
                return words[i];
            }
        }
        return "";
    }
};