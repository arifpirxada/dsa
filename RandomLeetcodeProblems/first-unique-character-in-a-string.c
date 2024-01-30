// https://leetcode.com/problems/first-unique-character-in-a-string/

int firstUniqChar(char* s) {
    int i, j, chk;

    for (i = 0; i < strlen(s); i++) {
        chk = 0;
        for (j = 0; j < strlen(s); j++) {
            if (i == j) {
                continue;
            }
            if (s[i] == s[j]) {
                chk = 1;
                break;
            }
        }
        if (chk == 0) {
            return i;
        }
    }

    return -1;
}