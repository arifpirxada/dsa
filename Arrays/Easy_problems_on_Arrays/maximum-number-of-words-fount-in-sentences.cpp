// https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/

class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxWords = 0, currWords;

        for (int i{}; i < sentences.size(); i++) {
            currWords = 1;
            for(int j{}; j < sentences[i].size(); j++) {
                if (sentences[i][j] == ' ') {
                    currWords++;
                }
            }
            if (maxWords < currWords) {
                maxWords = currWords;
            }
        }

        return maxWords;
    }
};