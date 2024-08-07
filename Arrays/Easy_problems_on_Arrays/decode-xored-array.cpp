// https://leetcode.com/problems/decode-xored-array/

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ans(encoded.size() + 1);
        ans[0] = first;

        for (int i{}; i < encoded.size(); i++) {
            ans[i + 1] = encoded[i] ^ ans[i];
        }
        return ans;
    }
};