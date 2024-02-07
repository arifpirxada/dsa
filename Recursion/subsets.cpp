#include <vector>
using namespace std;

// https://leetcode.com/problems/subsets/

class Solution {
public:
    vector<vector<int>> ans;

    void helper(vector<int> arr, vector<int> temp, int i) {
        if (i == arr.size()) {
            ans.push_back(temp);
            return;
        }

        temp.push_back(arr[i]);
        helper(arr, temp, i + 1);
        temp.pop_back();
        helper(arr, temp, i + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        helper(nums, temp, 0);
        return ans;
    }
};