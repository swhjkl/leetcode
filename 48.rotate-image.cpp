/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        auto &m = matrix;
        int n = m.size() - 1;
        for (int i = 0; i < m.size() / 2; i++) {
            for (int j = i; j < n - i; j++) {
                int carry = m[j][n-i];
                m[j][n-i] = m[i][j];

                m[i][j] = m[n-i][n-j];
                m[n-i][n-j] = carry;
                carry = m[i][j];

                m[i][j] = m[n-j][i];
                m[n-j][i] = carry;
            }
        }
    }
};
// @lc code=end

