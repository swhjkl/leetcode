/*
 * @lc app=leetcode id=714 lang=cpp
 *
 * [714] Best Time to Buy and Sell Stock with Transaction Fee
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> profit(prices.size(), vector<int>(2, 0));
        profit[0][0] = 0;
        profit[0][1] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            profit[i][1] = max(profit[i - 1][1], profit[i - 1][0] - prices[i]);
            profit[i][0] = max(profit[i - 1][0], profit[i - 1][1] + prices[i] - fee);
        }
        return profit.back()[0];
    }
};
// @lc code=end

