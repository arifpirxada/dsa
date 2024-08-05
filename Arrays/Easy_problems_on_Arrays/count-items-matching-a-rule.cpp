// https://leetcode.com/problems/count-items-matching-a-rule/

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int count = 0;
        for (int i{}; i < items.size(); i++) {
            if (ruleKey == "type" && ruleValue == items[i][0]) {
                count++;
            } else if (ruleKey == "color" && ruleValue == items[i][1]) {
                count++;
            } else if (ruleKey == "name" && ruleValue == items[i][2]) {
                count++;
            }
        }
        return count;
    }
};