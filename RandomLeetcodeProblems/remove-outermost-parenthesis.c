// https://leetcode.com/problems/remove-outermost-parentheses/

char* removeOuterParentheses(char* s) {
    char* result = (char*)malloc(strlen(s) * sizeof(char));
    int resIndex = 0;
    int opened = 0;

    for (int i = 0; i < strlen(s); i++) {
        char c = s[i];

        if (c == '(' && opened > 0) {
            result[resIndex++] = c;
        }
        if (c == ')' && opened > 1) {
            result[resIndex++] = c;
        }

        opened += (c == '(') ? 1 : -1;
    }

    result[resIndex] = '\0';

    return result;
}