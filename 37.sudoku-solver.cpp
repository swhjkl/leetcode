/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

// @lc code=start
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<vector<bool>>> pool(3, vector<vector<bool>>(3, vector<bool>(9, true)));
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    pool[i / 3][j / 3][board[i][j] - '1'] = false;
                }
            }
        }
        solveSudoku(0, 0, board, pool);
    }

private:
    bool solveSudoku(int i, int j, vector<vector<char>>& board,
        vector<vector<vector<bool>>> &pool) {
        if (j == 9) {
            i++;
            j = 0;
        }
        if (i == 9) {
            return true;
        }
        if (board[i][j] != '.') {
            return solveSudoku(i, j + 1, board, pool);
        }
        for (int k = 0; k < 9; k++) {
            if (!pool[i / 3][j / 3][k]) {
                continue;
            }
            char c = '1' + k;
            bool valid = true;
            for (int l = 0; l < 9; l++) {
                if (board[i][l] == c || board[l][j] == c) {
                    valid = false;
                    break;
                }
            }
            if (!valid) {
                continue;
            }
            board[i][j] = c;
            pool[i / 3][j / 3][k] = false;
            valid = solveSudoku(i, j + 1, board, pool);
            if (valid) {
                return true;
            }
            board[i][j] = '.';
            pool[i / 3][j / 3][k] = true;
        }
        return false;
    }
};
// @lc code=end

