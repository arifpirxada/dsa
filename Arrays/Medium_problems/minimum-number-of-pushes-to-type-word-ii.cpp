// https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/

class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> mp;
        int ans = 0;
        int uniqueCount = 0;

        // Count the frequency of each character
        for (char c : word) {
            mp[c]++;
        }

        vector<std::pair<char, int>> vec(mp.begin(), mp.end());

        // Sort the vector by frequencies in descending order
        sort(vec.begin(), vec.end(), [](const std::pair<char, int>& a, const std::pair<char, int>& b) {
            return a.second > b.second;
        });

        for (const auto& pair : vec) {
            int freq = pair.second;
            int cost = (uniqueCount < 8) ? 1 : (uniqueCount < 16) ? 2 : (uniqueCount < 24) ? 3 : 4;
            ans += cost * (freq);
            uniqueCount++;
        }

        return ans;
    }
};