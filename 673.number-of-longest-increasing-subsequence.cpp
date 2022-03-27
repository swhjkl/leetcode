/*
 * @lc app=leetcode id=673 lang=cpp
 *
 * [673] Number of Longest Increasing Subsequence
 */

// @lc code=start
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(2, 0));
        int max = 0;
        int ret = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            dp[i][0] = 1;
            dp[i][1] = 1;
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] < nums[j]) {
                    if (dp[j][0] + 1 == dp[i][0]) {
                        dp[i][1] += dp[j][1];
                    }
                    if (dp[j][0] + 1 > dp[i][0] ) {
                        dp[i][0] = dp[j][0] + 1;
                        dp[i][1] = dp[j][1];
                    }
                }
            }
            if (max == dp[i][0]) {
                ret += dp[i][1];
            }
            if (max < dp[i][0]) {
                ret = dp[i][1];
                max = dp[i][0];
            }
        }
        return ret;
    }
};
// @lc code=end

