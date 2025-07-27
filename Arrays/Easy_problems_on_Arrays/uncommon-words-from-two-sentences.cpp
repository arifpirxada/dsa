// https://leetcode.com/problems/uncommon-words-from-two-sentences/

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp;
        unordered_map<string, int> mp2;
        vector<string> ans;
        string temp = "";

        for (int i{}; i < s1.size(); i++) {
            if (s1[i] == ' ') {
                mp[temp]++;
                temp = "";
            } else {
                temp.push_back(s1[i]);
                if (i == s1.size() - 1) mp[temp]++;
            }
        }
        temp = "";
        for (int i{}; i < s2.size(); i++) {
            if (s2[i] == ' ') {
                mp[temp]++;
                temp = "";
            } else {
                temp.push_back(s2[i]);
                if (i == s2.size() - 1) mp[temp]++;
            }
        }
        for (auto pair: mp) {
            if (pair.second < 2 && mp2.find(pair.first) == mp2.end()) {
                ans.push_back(pair.first);
            }
        }
        return ans;
    }
};