// https://leetcode.com/problems/reverse-words-in-a-string-iii/

class Solution {
public:
    string reverseWords(string s) {
        int i, j, k, z, size = s.size();
        vector<string> words;
        string newS;
        i = 0;

        for (j = 0; j < size; j++) {
            while (s[j] != ' ' && j < size) {
                k = 0;
                string word;
                while (s[j] != ' ' && j < size) {
                    word += s[j];
                    j++;
                }
                words.push_back(word);
            }
        }

        for (auto& word : words) {
            z = 0;
            int wordSize = word.size();
            while (z < wordSize / 2) {
                char temp = word[z];
                word[z] = word[wordSize - z - 1];
                word[wordSize - z - 1] = temp;
                z++;
            }
            newS += word + ' ';
        }

        newS.pop_back();  // Remove the extra space at the end
        return newS;
    }
};
