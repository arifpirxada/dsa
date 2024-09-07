// https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/

// Passes 70 test cases
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        vector<long long> prefix(chalk.size());
        int times, sum;
        prefix[0] = chalk[0];

        for (int i = 1; i < chalk.size(); i++) {
            prefix[i] = prefix[i - 1] + chalk[i];
        }

        sum = prefix.back();
        times = k / sum;

        for (int i{}; i < chalk.size(); i++) {
            int prevSum = i > 0 ? prefix[i - 1] : 0;
            if ((k - ((sum * times) + prevSum)) < chalk[i]) {
                return i;
            }
        }

        return -1;
    }
};

// Good
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long total = 0;
        for (int i = 0; i < chalk.size(); ++i) {
            total += chalk[i];
        }

        k %= total;

        for (int i = 0; i < chalk.size(); ++i) {
            if (k < chalk[i]) {
                return i;
            }
            k -= chalk[i];
        }

        return -1;
    }
};