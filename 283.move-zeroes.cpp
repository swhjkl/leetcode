/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int fill_index = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) {
                nums[fill_index++] = nums[i];
            }
        }
        for (int i = fill_index; i < nums.size(); i++) {
            nums[i] = 0;
        }
        return;
    }
};
// @lc code=end

