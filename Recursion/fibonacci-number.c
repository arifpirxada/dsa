// https://leetcode.com/problems/fibonacci-number/

int fib(int n) {
    if (n == 1) {
        return 1;
    }
    if (n == 0) {
        return 0;
    }

    int firstCall = fib(n - 1);
    int secondCall = fib(n - 2);

    int result = firstCall + secondCall;

    return result;
}