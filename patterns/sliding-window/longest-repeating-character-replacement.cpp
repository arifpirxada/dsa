// https://leetcode.com/problems/longest-repeating-character-replacement/

class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0, j = 1, temp, n = s.size(), ans = 0;
        if (n == 1) return 1;

        while (j < n && i < n) {
            temp = k;
            while (j < n && temp > 0) {
                if (s[j] != s[i]) {
                    temp--;
                }
                j++;
            }
            while (s[j] == s[i]) {
                j++;
            }
            int x = i;
            while (x > 0 && temp > 0) {
                temp--;
                x--;
            }
            ans = max(ans, j - x);
            char prev = s[i];
            while (s[i] == prev) {
                i++;
            }
            j = i + 1;
        }

        return ans;
    }
};