// https://leetcode.com/problems/reverse-vowels-of-a-string/

class Solution {
private:
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    
    bool isVowel(char c) {
        return vowels.count(c) > 0;
    }
public:
    string reverseVowels(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            while (l < r && !isVowel(s[l])) {
                l++;
            }
            while (l < r && !isVowel(s[r])) {
                r--;
            }
            if (l < r) {
                swap(s[l], s[r]);
                l++;
                r--;
            }
        }
        return s;
    }
};