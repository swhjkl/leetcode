/*
 * @lc app=leetcode id=477 lang=cpp
 *
 * [477] Total Hamming Distance
 */

// @lc code=start
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < 32; i++) {
            int one = 0;
            for (auto &n : nums) {
                one += (n & 1);
                n = n>> 1;
            }
            result += one * (nums.size() - one);
        }
        return result;
    }
};
// @lc code=end