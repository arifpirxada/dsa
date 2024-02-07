#include <stdbool.h>
// https://leetcode.com/problems/valid-anagram/

int compareChars(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

bool isAnagram(char* s, char* t) {

    if (strlen(s) != strlen(t)) {
        return false;
    }

    qsort(s, strlen(s), sizeof(char), compareChars);
    qsort(t, strlen(t), sizeof(char), compareChars);

    return strcmp(s, t) == 0;  
}