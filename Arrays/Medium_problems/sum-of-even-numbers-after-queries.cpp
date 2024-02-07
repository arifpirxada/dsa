#include <vector>
using namespace std;

// https://leetcode.com/problems/sum-of-even-numbers-after-queries/

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        std::vector<int> ans;
        int i, j, evenSum, k = 0;

        for (i = 0; i < queries.size(); i++) {
            evenSum = 0;
            nums[queries[i][1]] = nums[queries[i][1]] + queries[i][0];

            for (j = 0; j < nums.size(); j++) {
                if (nums[j] % 2 == 0) {
                    evenSum += nums[j];
                }
            }
            ans.push_back(evenSum);
        }
        return ans;
    }
};