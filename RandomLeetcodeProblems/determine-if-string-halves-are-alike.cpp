// https://leetcode.com/problems/determine-if-string-halves-are-alike/

class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    bool halvesAreAlike(string s) {
        vector<char> first, second;
        int i;

        for (i = 0; i < s.size() / 2; i++) {
            if (isVowel(s[i])) {
                first.push_back(s[i]);
            }
        }

        while (i < s.size()) {
            if (isVowel(s[i])) {
                second.push_back(s[i]);
            }
            i++;
        }
        return first.size() == second.size();
    }
};