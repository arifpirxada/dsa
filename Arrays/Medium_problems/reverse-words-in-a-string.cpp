// https://leetcode.com/problems/reverse-words-in-a-string/

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans;
        int i = n - 1, j;
        while (i >= 0) {
            while (i >= 0 && s[i] == ' ') i--;
            if (i < 0) break;
            j = i;
            while (j >= 0 && s[j] != ' ') j--;
            
            if (!ans.empty()) ans += ' ';
            ans += s.substr(j + 1, i - j);
            i = j - 1;
        }
        return ans;
    }
};