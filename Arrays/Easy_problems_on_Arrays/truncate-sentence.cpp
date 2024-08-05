// https://leetcode.com/problems/truncate-sentence/

class Solution {
public:
    string truncateSentence(string s, int k) {
        int spaces = 0;
        for (int i{}; i < s.size(); i++) {
            if (s[i] == ' ') spaces++;
            if (spaces == k) {
                s = s.substr(0, i);
            }
        }
        return s;
    }
};