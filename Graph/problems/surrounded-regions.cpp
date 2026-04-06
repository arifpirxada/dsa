// https://leetcode.com/problems/surrounded-regions

class Solution {
public:
    void markDFS(vector<vector<char>>& board, int i, int j, vector<vector<bool>>& canChange) {
        if (i < 0 || j < 0 || i == board.size() || j == board[0].size() || board[i][j] == 'X' || canChange[i][j] == false) return;

        canChange[i][j] = false;

        markDFS(board, i - 1, j, canChange);
        markDFS(board, i + 1, j, canChange);
        markDFS(board, i, j - 1, canChange);
        markDFS(board, i, j + 1, canChange);
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> canChange(m, vector<bool> (n, true));

        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O')
                markDFS(board, i, 0, canChange);

            if (board[i][n - 1] == 'O')
                markDFS(board, i, n - 1, canChange);
        }

        for (int i = 0; i < n; i++) {
            if (board[0][i] == 'O')
                markDFS(board, 0, i, canChange);
            
            if (board[m - 1][i] == 'O')
                markDFS(board, m - 1, i, canChange);
        }

        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (board[i][j] == 'O' && canChange[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};