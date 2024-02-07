// https://leetcode.com/problems/to-lower-case/

char lowerize(char ch) {
    return ch - 'A' + 'a';
}

char* toLowerCase(char* s) {
    for (int i = 0; i < strlen(s); i++) {
        if (isupper(s[i])) {
            s[i] = lowerize(s[i]);
        }
    }

    return s;
}