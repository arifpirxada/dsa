// https://leetcode.com/problems/maximum-value-of-a-string-in-an-array/

int maximumValue(char** strs, int strsSize) {
    int i, j, max = 0, digit = 1, numVal = 0;

    for (i = 0; i < strsSize; i++) {
        digit = 1;
        numVal = 0;

        for (j = 0; strs[i][j] != '\0'; j++) {
            if (isdigit(strs[i][j]) && digit) {
                numVal = (numVal * 10) + (strs[i][j] - '0');
            } else {
                digit = 0;
            }
        }
        if (digit && numVal > max) {
            max = numVal;
        } else if (j > max && !digit) {
            max = j;
        }
    }

    return max;
}