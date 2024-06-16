// https://leetcode.com/problems/combination-sum/

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void helper(vector<int>& candidates, int target, int currSum, int i, vector<int> temp) {
        if (currSum > target) {
            return;
        } 
        if (i >= candidates.size()) {
            if (currSum == target) {
                ans.push_back(temp);
            }
            return;
        }

        currSum += candidates[i];
        temp.push_back(candidates[i]);
        helper(candidates, target, currSum, i, temp);
        currSum -= candidates[i];
        temp.pop_back();

        helper(candidates, target, currSum, i + 1, temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        helper(candidates, target, 0, 0, temp);
        return ans;
    }
};