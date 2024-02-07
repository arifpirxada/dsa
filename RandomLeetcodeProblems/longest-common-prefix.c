// https://leetcode.com/problems/longest-common-prefix/

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) {
        return "";  // Empty array, no common prefix
    }

    int i, j = 0;
    int commonLength = strlen(strs[0]);
    char *commonStr = (char *)malloc((commonLength + 1) * sizeof(char));

    strcpy(commonStr, strs[0]);

    for (i = 1; i < strsSize; i++) {
        j = 0;
        while (commonStr[j] && strs[i][j] && commonStr[j] == strs[i][j]) {
            j++;
        }
        commonStr[j] = '\0';
        commonLength = j;
    }

    return commonStr;
}