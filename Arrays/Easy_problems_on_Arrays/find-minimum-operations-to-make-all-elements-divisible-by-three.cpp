// https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int numOperations = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 3 != 0) {
                numOperations++;
            }
        }

        return numOperations;
    }
};