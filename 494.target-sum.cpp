/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (target > sum || target < -sum) {
            return 0;
        }
        vector<int> dp(sum * 2 + 1, 0);
        dp[nums[0] + sum] = 1;
        dp[-nums[0] + sum] += 1;
        for (int i = 1; i < nums.size(); i++) {
            vector<int> next(sum * 2 + 1, 0);
            for (int j = -sum; j <= sum; j++) {
                if (dp[j + sum]) {
                    next[j + sum + nums[i]] += dp[j + sum];
                    next[j + sum - nums[i]] += dp[j + sum];
                }
            }
            dp = next;
        }
        return dp[target + sum];
    }
};
// @lc code=end
