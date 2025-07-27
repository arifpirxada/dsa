// https://leetcode.com/problems/largest-number

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strNums;
        for (int num : nums) {
            strNums.push_back(to_string(num));
        }

        auto myComparator = [](const string &s1, const string &s2) {
            return s1 + s2 > s2 + s1;
        };
        sort(strNums.begin(), strNums.end(), myComparator);

        if (strNums[0] == "0") {
            return "0";
        }

        std::string result;
        for (const string &s : strNums) {
            result += s;
        }

        return result;
    }
};