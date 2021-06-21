/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }
        int prev_prev[2] = {nums[0], nums[1]};
        int prev[2] = {max(nums[0], nums[1]), max(nums[1], nums[2])};
        for (int j = 0; j < 2; j++) {
            for (int i = 2 + j; i < nums.size() - 1 + j; i++) {
                int profit = max(prev_prev[j] + nums[i], prev[j]);
                prev_prev[j] = prev[j];
                prev[j] = profit;
            }
        }
        return max(prev[0], prev[1]);
    }
};
// @lc code=end

