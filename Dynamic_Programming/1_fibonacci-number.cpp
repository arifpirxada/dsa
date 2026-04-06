#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/fibonacci-number/

class SolutionRecur {
public:
    int fibRecur(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        return fibRecur(n - 1) + fibRecur(n - 2);
    }
    int fib(int n) {
        return fibRecur(n);
    }
};

class SolutionMem {
public:
    int fibRecurMem(int n, vector<int>& dp) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        if (dp[n] != -1) return dp[n];

        dp[n] = fibRecurMem(n - 1, dp) + fibRecurMem(n - 2, dp);
        return dp[n];
    }
    int fib(int n) {
        vector<int> dp(n + 1, -1);
        return fibRecurMem(n, dp);
    }
};

class SolutionTable {
public:
    int fib(int n) {
        if (n <= 1) return n;
        vector<int> dp(n + 1, -1);

        dp[0] = 0;
        dp[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

class SolutionTableSpaceOpt {
public:
    int fib(int n) {
        if (n <= 1) return n;
        int curr, prev2 = 0, prev1 = 1;
        
        for (int i = 2; i <= n; i++) {
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
};

int main() {
    // Fibonacci Sequence: 0 1 1 2 3 5 8 13 21 34

    SolutionTableSpaceOpt s;

    int ans = s.fib(9);
    cout << "Answer: " << ans; // Expected 34

    return 0;
}