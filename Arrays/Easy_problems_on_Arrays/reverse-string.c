// https://leetcode.com/problems/reverse-string/

void reverseString(char* s, int sSize) {
    int i;
    char temp;

    for (i = 0; i < sSize / 2; i ++) {
        temp = s[i];
        s[i] = s[sSize - (i + 1)];
        s[sSize - (i + 1)] = temp;
    }
}