// https://leetcode.com/problems/length-of-last-word/

int lengthOfLastWord(char* s) {
    int i, len = 0, wordCame = 0;

    for (i = strlen(s) - 1; i >= 0; i--) {
        if (s[i] == ' '&& !wordCame) {
            continue;
        }
        wordCame = 1;
        if (s[i] == ' ') {
            break;
        }
        len++;
    }

    return len;
}