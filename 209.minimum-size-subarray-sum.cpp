/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = INT_MAX;
        int sum = 0;
        int l = 0;
        int r = 0;
        while (r < nums.size()) {
            sum += nums[r++];
            while (sum >= target) {
                len = min(len, r - l);
                sum -= nums[l++];
            }
        }
        return len == INT_MAX ? 0 : len;
    }
};
// @lc code=end

