// https://leetcode.com/problems/number-of-senior-citizens/

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0, n = details.size();
        string age;
        int intAge;
        for (int i{}; i < n; i++) {
            age = details[i].substr(11, 2);
            intAge = stoi(age);
            if (intAge > 60) {
                count++;
            }
        }
        return count;
    }
};