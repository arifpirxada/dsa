// https://leetcode.com/problems/expressive-words/

class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        int count = 0;

        for (string word : words) {
            int i = 0, j = 0;
            bool isValid = true;

            while (i < s.size() && j < word.size()) {
                if (s[i] != word[j]) {
                    isValid = false;
                    break;
                }

                int strCount = 0;
                char currentChar = s[i];
                while (i < s.size() && s[i] == currentChar) {
                    strCount++;
                    i++;
                }

                int wordCount = 0;
                while (j < word.size() && word[j] == currentChar) {
                    wordCount++;
                    j++;
                }

                if (strCount < wordCount || (strCount < 3 && strCount != wordCount)) {
                    isValid = false;
                    break;
                }
            }

            if (i == s.size() && j == word.size() && isValid) {
                count++;
            }
        }

        return count;
    }
};