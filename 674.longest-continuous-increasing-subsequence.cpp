/*
 * @lc app=leetcode id=674 lang=cpp
 *
 * [674] Longest Continuous Increasing Subsequence
 */

// @lc code=start
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int start = 0;
        int end = 1;
        int max_len = 1;
        for (; end < nums.size(); end++) {
            if (nums[end] <= nums[end - 1]) {
                int len = end - start;
                if (len > max_len) {
                    max_len = len;
                }
                start = end;
            }
        }
        int len = end - start;
        return max_len > len ? max_len : len;
    }
};
// @lc code=end

