// https://leetcode.com/problems/find-missing-observations

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int totalSum = mean * (rolls.size() + n), mSum = 0;
        vector<int> ans(n, 0);
        for (int roll : rolls) {
            mSum += roll;
        }
        int nSum = totalSum - mSum;
        int element = nSum / n;
        if (mSum > totalSum || nSum < n) {
            return {};
        }
        int addition = nSum % n;

        if (element > 6) {
            return {};
        }
        for (int i{}; i < n; i++) {
            ans[i] = element;
            cout << element << " ;";
            if (addition >= 6 - ans[i]) {
                addition -= 6 - ans[i];
                ans[i] += 6 - ans[i];
            } else {
                ans[i] += addition;
                addition = 0;
            }
        }

        if (addition != 0) {
            return {};
        }
        return ans;        
    }
};