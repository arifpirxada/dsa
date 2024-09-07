// https://leetcode.com/problems/check-if-a-string-is-an-acronym-of-words/

class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        string temp;

        for (int i{}; i < words.size(); i++) {
            temp += words[i][0];
        }

        return temp == s;
    }
};