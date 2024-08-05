// https://leetcode.com/problems/kth-distinct-string-in-an-array/

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;

        for (int i{}; i < arr.size(); i++) {
            auto it = mp.find(arr[i]);
            if (it != mp.end()) {
                it->second++;
            } else {
                mp[arr[i]] = 1;
            }
        }

        int index = 0;
        for (int i{}; i < arr.size(); i++) {
            if (mp[arr[i]] == 1) {
                index++;
            }
            if (index == k) {
                return arr[i];
            }
        }
        return "";
    }
};