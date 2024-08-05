// https://leetcode.com/problems/shuffle-string/

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n = s.size();
        string ans(n, ' ');

        for (int i{}; i < n; i++) {
            ans[indices[i]] = s[i];
        }
        return ans;
    }
};