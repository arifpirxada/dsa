// https://leetcode.com/problems/string-compression/

class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0, j = 1, n = chars.size(), k = 0;
        if (n == 1) return 1;

        while (j < n) {
            while (j < n && chars[j] == chars[i]) {
                j++;
            }
            chars[k++] = chars[i];
            if (j - i > 1) {
                if (j - i >= 10) {
                    string count = to_string(j - i);
                    for (char c : count) {
                        chars[k++] = c;
                    }
                } else {
                    chars[k++] = (j - i) + '0';
                }
            }
            i = j;
        }
        return k;
    }
};