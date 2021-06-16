/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] > 0) {
                nums[i] += nums[i - 1];
            }
            if (nums[i] > max) {
                max = nums[i];
            }
        }
        return max;
    }
};
// @lc code=end

