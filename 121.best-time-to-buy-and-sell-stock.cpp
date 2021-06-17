/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;
        int max_profit = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < min_price) {
                min_price = prices[i];
            } else if (max_profit < prices[i] - min_price) {
                max_profit = prices[i] - min_price;
            }
        }
        return max_profit;
    }
};
// @lc code=end

