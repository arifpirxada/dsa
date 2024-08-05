// https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string first;
        string second;
        int i, n = word1.size(), n2 = word2.size();

        for (auto word: word1) {
            first += word;
        }
        for (auto word: word2) {
            second += word;
        }
        return first == second;
    }
};