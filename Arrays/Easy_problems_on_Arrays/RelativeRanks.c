// https://leetcode.com/problems/relative-ranks/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findRelativeRanks(int* score, int scoreSize, int* returnSize) {
    int i, j, rank;
    *returnSize = 0;
    char **answer = (char **)malloc(scoreSize * sizeof(char *));

    for (i = 0; i < scoreSize; i++) {
        rank = 1;
        for (j = 0; j < scoreSize; j++) {
            if (i == j) {
                continue;
            }
            if (score[i] < score[j]) {
                rank++;
            }
        }
        if (rank == 1) {
            answer[*returnSize] = (char *)malloc(20 * sizeof(char));
            strcpy(answer[*returnSize], "Gold Medal");
            (*returnSize)++;
        } else if (rank == 2) {
            answer[*returnSize] = (char *)malloc(20 * sizeof(char));
            strcpy(answer[*returnSize], "Silver Medal");
            (*returnSize)++;
        } else if (rank == 3) {
            answer[*returnSize] = (char *)malloc(20 * sizeof(char));
            strcpy(answer[*returnSize], "Bronze Medal");
            (*returnSize)++;
        } else {
            answer[*returnSize] = (char *)malloc(12 * sizeof(char));
            snprintf(answer[*returnSize], 12, "%d", rank);
            (*returnSize)++;
        }
    }
    return answer;
}