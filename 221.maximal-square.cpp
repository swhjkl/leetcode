/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 *
 * https://leetcode.com/problems/maximal-square/description/
 *
 * algorithms
 * Medium (43.19%)
 * Likes:    6880
 * Dislikes: 144
 * Total Accepted:    475.8K
 * Total Submissions: 1.1M
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given an m x n binary matrix filled with 0's and 1's, find the largest
 * square containing only 1's and return its area.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix =
 * [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
 * Output: 4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = [["0","1"],["1","0"]]
 * Output: 1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: matrix = [["0"]]
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 300
 * matrix[i][j] is '0' or '1'.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
      vector<int> square_len(matrix[0].size(), 0);
      int prev = 0;
      int max_len = 0;
      for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
          if (matrix[i][j] == '0') {
            square_len[j] = 0;
          } else {
            int min = prev;
            if (i != 0 && j != 0) {
              if (min > square_len[j - 1]) {
                min = square_len[j - 1];
              }
              if (min > square_len[j]) {
                min = square_len[j];
              }
            } else {
              min = 0;
            }
            prev = square_len[j];
            square_len[j] = min + 1;
          }
          if (square_len[j] > max_len) {
            max_len = square_len[j];
          }
        }
      }
      return max_len * max_len;
    }
};
// @lc code=end

