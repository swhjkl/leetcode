/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int iMin = -1, iMax = matrix.size(), jMin = -1, jMax = matrix[0].size();
        enum {
            RIGHT,
            DOWN,
            LEFT,
            UP
        } direction = RIGHT;
        int i = 0, j = 0;
        vector<int> ret;
        while (true) {
            ret.push_back(matrix[i][j]);
            switch (direction) {
            case RIGHT:
                if (j + 1 < jMax) {
                    j += 1;
                } else if (i + 1 < iMax) {
                    direction = DOWN;
                    iMin = i;
                    i += 1;
                } else {
                    return ret;
                }
                break;
            case DOWN:
                if (i + 1 < iMax) {
                    i += 1;
                } else if (j - 1 > jMin) {
                    direction = LEFT;
                    jMax = j;
                    j -= 1;
                } else {
                    return ret;
                }
                break;
            case LEFT:
                if (j - 1 > jMin) {
                    j -= 1;
                } else if (i - 1 > iMin) {
                    direction = UP;
                    iMax = i;
                    i -= 1;
                } else {
                    return ret;
                }
                break;
            case UP:
                if (i - 1 > iMin) {
                    i -= 1;
                } else if (j + 1 < jMax) {
                    direction = RIGHT;
                    jMin = j;
                    j += 1;
                } else {
                    return ret;
                }
                break;
            }
        }
        return ret;
    }
};
// @lc code=end

