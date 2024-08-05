// https://leetcode.com/problems/count-the-number-of-consistent-strings/

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int n = 0;
        bool found;

        for (int i{}; i < words.size(); i++) {
            found = true;
            for (auto c: words[i]) {
                size_t character = allowed.find(c);
                if (character == std::string::npos) {
                    // Character was not found
                    found = false;
                    break;
                }
            }
            if (found) {
                n++;
            }
        }

        return n;
    }
};