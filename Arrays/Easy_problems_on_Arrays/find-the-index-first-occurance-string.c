// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

int strStr(char* haystack, char* needle) {
    int haystackSize = strlen(haystack);
    int needleSize = strlen(needle);
    int i, j, consec = 0;

    for (i = 0; i <= haystackSize - needleSize; i++) {
        for (j = 0; j < needleSize; j++) {
            if (haystack[i + j] != needle[j]) {
                break;
            }
        }
        if (j == needleSize) {
            return i;
        }
    }

    return -1;
}