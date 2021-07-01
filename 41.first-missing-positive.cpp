/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {                               
        for (auto &i : nums) {
            if (i <= 0) {
                i = INT_MAX;
            }
        }
        for (auto &i : nums) {
            if (abs(i) <= nums.size() && nums[abs(i) - 1] > 0) {
                nums[abs(i) - 1] *= -1;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
};
// @lc code=end

