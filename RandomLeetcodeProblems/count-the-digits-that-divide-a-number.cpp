class Solution {
public:
    int countDigits(int num) {
        int number = num;
        int count = 0;
        int digit;

        while (number > 0) {
            digit = number % 10;
            number = number / 10;

            if (num % digit == 0) {
                count++;
            }
        }

        return count;
    }
};