// https://leetcode.com/problems/sum-of-digits-of-string-after-convert/

class Solution {
public:
    int getLucky(string s, int k) {
        long long sum = 0;

        for (char c : s) {
            int digit = c - 'a' + 1;
            sum += digit < 10 ? digit : (digit % 10 + digit / 10);
        }

        for (int i = 0; i < k - 1; i++) {
            long long newSum = 0;
            while (sum > 0) {
                newSum += sum % 10;
                sum /= 10;
            }
            sum = newSum;
        }

        return sum;
    }
};