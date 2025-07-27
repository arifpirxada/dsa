// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/

class Solution {
public:
    bool isVowel (char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
        return false;
    }
    int maxVowels(string s, int k) {
        int i = 0, j = 0, count = 0, ans = 0;

        while (j < k) {
            if (isVowel(s[j])) count++;
            j++;
        }
        ans = count;

        while (j < s.size()) {
            if (isVowel(s[i])) count--;
            if (isVowel(s[j])) count++;
            ans = max(ans, count);
            i++;
            j++;        
        }
        return ans;
    }
};