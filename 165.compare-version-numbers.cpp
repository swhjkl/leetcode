/*
 * @lc app=leetcode id=165 lang=cpp
 *
 * [165] Compare Version Numbers
 */

// @lc code=start
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i1 = 0, i2 = 0;
        while (i1 < version1.size() || i2 < version2.size()) {
            int r1 = 0;
            while (i1 < version1.size() && version1[i1] != '.') {
                r1 = r1 * 10 + (version1[i1++] - '0');
            }
            int r2 = 0;
            while (i2 < version2.size() && version2[i2] != '.') {
                r2 = r2 * 10 + (version2[i2++] - '0');
            }

            if (r1 != r2) {
                return r1 < r2 ? -1 : 1;
            }

            i1++;
            i2++;
        }
        return 0;
    }
};
// @lc code=end

