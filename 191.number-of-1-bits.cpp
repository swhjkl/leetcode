/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

// @lc code=start
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        while (n > 0) {
            ret++;
            n &= (n-1);
        }
        return ret;
    }
};
// @lc code=end