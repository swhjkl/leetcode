/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (exist(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    int m;
    int n;
    bool exist(vector<vector<char>>& board, int i, int j, const string &w, int k) {
        if (k == w.size()) {
            return true;
        }
        if (i < 0 || i > m - 1 || j < 0 || j > n - 1 || board[i][j] != w[k]) {
            return false;
        }
        char tmp = board[i][j];
        board[i][j] = 0;
        if (exist(board, i, j - 1, w, k + 1) ||
            exist(board, i, j + 1, w, k + 1) ||
            exist(board, i - 1, j, w, k + 1) ||
            exist(board, i + 1, j, w, k + 1)) {
            return true;
        }
        board[i][j] = tmp;
        return false;
    }
};
// @lc code=end

