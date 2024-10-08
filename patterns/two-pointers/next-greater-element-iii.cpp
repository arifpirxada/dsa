// https://leetcode.com/problems/next-greater-element-iii/

class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> digits;
        
        while (n > 0) {
            digits.push_back(n % 10);
            n /= 10;
        }
        
        reverse(digits.begin(), digits.end());
        
        int i = digits.size() - 2;
        while (i >= 0 && digits[i] >= digits[i + 1]) {
            i--;
        }
        
        if (i < 0) {
            return -1;
        }
        
        int j = digits.size() - 1;
        
        while (digits[j] <= digits[i]) {
            j--;
        }
        
        swap(digits[i], digits[j]);
        sort(digits.begin() + i + 1, digits.end());
        
        long long ans = 0;
        for (int digit : digits) {
            ans = ans * 10 + digit;
        }
        
        if (ans > INT_MAX) {
            return -1;
        }
        
        return static_cast<int>(ans);
    }
};