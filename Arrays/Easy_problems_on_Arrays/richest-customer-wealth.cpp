// https://leetcode.com/problems/richest-customer-wealth/

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = 0;
        int currWealth;

        for (int i{}; i < accounts.size(); i++) {
            currWealth = 0;
            for (int j{}; j < accounts[i].size(); j++) {
                currWealth += accounts[i][j];
            }
            if (currWealth > maxWealth) {
                maxWealth = currWealth;
            }
        }

        return maxWealth;
    }
};