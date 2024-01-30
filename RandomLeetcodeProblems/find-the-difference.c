// leetcode.com/problems/find-the-difference/

char findTheDifference(char* s, char* t) {
    int i;
    int sum_t = 0;
    int sum_s = 0;

    for (i = 0; s[i] != '\0'; i++) {
        sum_s += s[i];
        sum_t += t[i];
    }
    sum_t += t[strlen(t) - 1];

    return (char)(sum_t - sum_s);
}