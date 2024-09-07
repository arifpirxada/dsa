// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 1, n = s.size(), ans = 0;
        if (n <= 1) return n;
        unordered_map<char, int> mp;
        mp[s[0]] = 1;

        while(j < n) {
            while (j < n) {
                if (mp.find(s[j]) == mp.end() || mp[s[j]] == 0) {
                    mp[s[j]] = 1;
                    j++;
                } else {
                    break;
                }
            }
            ans = max(ans, j - i);
            while (i <= j && s[i] != s[j]) {
                mp[s[i]] = 0;
                i++;
            }
            mp[s[i]] = 0;
            i++;
        }
        return ans;
    }
};