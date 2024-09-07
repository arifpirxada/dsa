// https://leetcode.com/problems/spiral-matrix-iv/

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        ListNode* ptr = head;
        int startRow = 0, endRow = m - 1, startColumn = 0, endColumn = n - 1;

        while (startRow <= endRow && startColumn <= endColumn) {
            int i, j;
            for (j = startColumn; j <= endColumn; j++) {
                if (ptr) {
                    matrix[startRow][j] = ptr->val;
                    ptr = ptr->next;
                }
            }
            startRow++;

            for(i = startRow; i <= endRow; i++) {
                if (ptr) {
                    matrix[i][endColumn] = ptr->val;
                    ptr = ptr->next;
                }
            }
            endColumn--;

            for(j = endColumn; j >= startColumn; j--) {
                if (ptr) {
                    matrix[endRow][j] = ptr->val;
                    ptr = ptr->next;
                }
            }
            endRow--;

            for (i = endRow; i >= startRow; i--) {
                if (ptr) {
                    matrix[i][startColumn] = ptr->val;
                    ptr = ptr->next;
                }
            }
            startColumn++;
        }

        return matrix;
    }
};