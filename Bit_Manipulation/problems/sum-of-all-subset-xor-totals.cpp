// https://leetcode.com/problems/sum-of-all-subset-xor-totals/

class Solution {
public:
    void generateSubsets(vector<int>& nums, vector<vector<int>>& subsets, vector<int>&currentSubset, int index) {
        if (index == nums.size()) {
            subsets.push_back(currentSubset);
            return;
        }
        
        generateSubsets(nums, subsets, currentSubset, index + 1);
        
        currentSubset.push_back(nums[index]);
        generateSubsets(nums, subsets, currentSubset, index + 1);
        currentSubset.pop_back();
    }
    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> currentSubset;
        generateSubsets(nums, subsets, currentSubset, 0);

        int XORTotal = 0, subsetXOR;
        for (auto subset: subsets) {
            subsetXOR = 0;
            for (int num: subset) {
                subsetXOR ^= num;
            }
            XORTotal += subsetXOR;
        }
        return XORTotal;
    }
};