// https://leetcode.com/problems/sort-vowels-by-frequency/

class Solution {
public:
    bool isVowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
        return false;
    }
    string sortVowels(string s) {
        int k = s.size();
        string sortedVowels; string ans(k, ' ');
        unordered_map<char, int> mp;
        unordered_map<char, int> mpInd;
        priority_queue<tuple<int, int, char>> pq;

        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])) {
                if (mpInd.find(s[i]) == mpInd.end()) {
                    mpInd[s[i]] = i;
                }
                mp[s[i]]++;
            } else {
                ans[i] = s[i];
            }
        }

        for (auto [c, freq] : mp) {
            pq.push({freq, -mpInd[c], c});
        }

        int j = 0;
        while (!pq.empty()) {
            auto [freq, negIdx, c] = pq.top();

            while (j < s.size() && freq > 0) {
                if (ans[j] == ' ') {
                    ans[j] = c;
                    freq--;
                }
                j++;
            }
            pq.pop();
        }
        return ans;
    }
};