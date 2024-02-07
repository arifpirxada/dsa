#include <stdbool.h>
// https://leetcode.com/problems/detect-capital/

bool detectCapitalUse(char* word) {
    int i, first = 0, small = 0,capital = 0;

    if (isupper(word[0])) {
        first = 1;
        capital++;
    } else {
        small++;
    }

    for (i = 1; i < strlen(word); i++) {
        if (isupper(word[i])) {
            capital++;
        } else {
            small++;
        }
    }

    if (first == 1 && capital == 1 && small == strlen(word) - 1) {
        return true;
    }
    if (capital == strlen(word) && small == 0) {
        return true;
    }
    if (small == strlen(word) && capital == 0) {
        return true;
    }

    return false;
}