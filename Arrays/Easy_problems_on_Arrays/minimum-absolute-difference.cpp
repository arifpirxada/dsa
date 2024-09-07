// https://leetcode.com/problems/minimum-absolute-difference/

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int minDiff = INT_MAX;
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());

        for (int i = 0; i < arr.size() - 1; i++) {
            int diff = abs(arr[i + 1] - arr[i]);
            if (diff < minDiff) {
                minDiff = diff;
                ans.clear();
                ans.push_back({arr[i], arr[i + 1]});
            } else if (diff == minDiff) {
                ans.push_back({arr[i], arr[i + 1]});
            }
        }

        return ans;
    }
};