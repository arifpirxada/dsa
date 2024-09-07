// https://leetcode.com/problems/sum-of-subarray-minimums/

// Time limit exceeded
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int MOD = 1e9 + 7;
        int currMin, totalSum = 0;

        for (int i{}; i < arr.size(); i++) {
            currMin = arr[i];
            totalSum += arr[i];
            for (int j = i + 1; j < arr.size(); j++) {
                currMin = min(currMin, arr[j]);
                totalSum = (totalSum + currMin) % MOD;
            }
        }

        return totalSum;
    }
};