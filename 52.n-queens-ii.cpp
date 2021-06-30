/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 */

// @lc code=start
class Solution {
public:
    int totalNQueens(int n) {
        int result = 0;
        string board_line(n, '.');
        vector<string> board(n, board_line);
        solveNQueens(n, 0, board, result);
        return result;
    }

private:
    void solveNQueens(int n, int k, vector<string> &board, int &result) {
        if (k == n) {
            result++;
            return;
        }
        for (int i = 0; i < n; i++) {
            bool ok = true;
            for (int j = 0; j < k; j++) {
                if (board[j][i] == 'Q' ||
                    (i - (k - j) >= 0 && board[j][i - (k - j)] == 'Q') ||
                    (i + (k - j) < n && board[j][i + (k - j)] == 'Q')) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                board[k][i] = 'Q';
                solveNQueens(n, k + 1, board, result);
                board[k][i] = '.';
            }
        }
    }
};
// @lc code=end

